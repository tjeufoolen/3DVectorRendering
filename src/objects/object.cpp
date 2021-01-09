#include "object.h"

#include <iostream>
#include <algorithm>

namespace objects {
    int object::current_id;

    object::object(const models::point3d& origin, bool showAxis, bool collidable)
        :   id_{current_id++},
            origin_{origin},
            heading_{0,0,1},
            collidable_{collidable}
    {
        if (showAxis) {
            addLine({models::point3d{0,0,0}, models::point3d{50,0,0}, config::X_AXIS_COLOUR});
            addLine({models::point3d{0,0,0}, models::point3d{0,50,0}, config::Y_AXIS_COLOUR});
            addLine({models::point3d{0,0,0}, models::point3d{0,0,50}, config::Z_AXIS_COLOUR});
        }
    }

    int object::id() const {
        return id_;
    }

    void object::transform(const models::Matrix &m) {
        for (auto &line : lines_) {
            line.begin().transform(m);
            line.end().transform(m);
        }

        heading_.transform(m);
    }

    models::line3d& object::addLine(models::line3d line) {
        return lines_.emplace_back(line);
    }

    std::vector<models::line3d>& object::lines() {
        return lines_;
    }

    void object::origin(double x, double y, double z) {
        origin_.x(x);
        origin_.y(y);
        origin_.z(z);
    }

    models::point3d object::origin() const {
        return origin_;
    }

    models::point3d& object::origin() {
        return origin_;
    }

    const models::point3d & object::heading() const {
        return heading_;
    }

    models::point3d object::centrum() const {
        double xTotal{0}, yTotal{0}, zTotal{0};
        auto points { lines_.size() * 2 }; // every line has 2 points

        for (auto& line : lines_) {
            auto begin { line.begin() };
            auto end   { line.end()   };

            xTotal += begin.x() + end.x();
            yTotal += begin.y() + end.y();
            zTotal += begin.z() + end.z();
        }

        return {
            xTotal / points,
            yTotal / points,
            zTotal / points
        };
    }

    bool object::discard() {
        return discard_;
    }

    bool object::collidable() const {
        return collidable_;
    }

    void object::onCollision(const objects::object &other) {
        discard_ = true;
    }

    // naive collision checking
    bool object::collides(const objects::object &other) const {
        if (!collidable_ || !other.collidable()) return false;

        double lowestX{}, lowestY{}, lowestZ{}, highestX{}, highestY{}, highestZ{};

        // calculate own bounding box
        std::for_each(lines_.begin(), lines_.end(), [&](auto& line){
            auto b{line.begin()}, e{line.end()};

            if (b.x() < lowestX)  lowestX  = b.x();
            if (b.x() > highestX) highestX = b.x();
            if (b.y() < lowestY)  lowestY  = b.y();
            if (b.y() > highestY) highestY = b.y();
            if (b.z() < lowestZ)  lowestZ  = b.z();
            if (b.z() > highestZ) highestZ = b.z();

            if (e.x() < lowestX)  lowestX  = e.x();
            if (e.x() > highestX) highestX = e.x();
            if (e.y() < lowestY)  lowestY  = e.y();
            if (e.y() > highestY) highestY = e.y();
            if (e.z() < lowestZ)  lowestZ  = e.z();
            if (e.z() > highestZ) highestZ = e.z();

            lowestX += origin().x(), highestX += origin().x();
            lowestY += origin().y(), highestY += origin().y();
            lowestZ += origin().z(), highestZ += origin().z();
        });

        // check if any point of other is between bounding box
        auto pointBetweenBoundingBox { [&](models::point3d p) -> bool {
            return  (p.x() >= lowestX && p.x() <= highestX) &&
                    (p.y() >= lowestY && p.y() <= highestY) &&
                    (p.z() >= lowestZ && p.z() <= highestZ);
        }};

        // loop through all points of other
        for (auto& line : other.lines_) {
            if (pointBetweenBoundingBox(line.begin() + other.origin()) ||
                pointBetweenBoundingBox(line.end() + other.origin()))
            {
                return true;
            }
        }

        return false;
    }

    void object::print() {
        std::for_each(lines_.begin(), lines_.end(), [](auto& line){ line.print(); });
    }
}