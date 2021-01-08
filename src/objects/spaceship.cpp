#include "spaceship.h"

#include "bullet.h"

#include "world.h"

namespace objects {
    spaceship::spaceship(const models::point3d& origin, models::world& world)
        :   world_{world},
            object{origin}
    {
        addLine({{78.1084,30,-100},{68.9468,46.821,-100}});
        addLine({{68.9468,46.821,-100},{72.3757,40.5256,-91.9498}});
        addLine({{72.3757,40.5256,-91.9498},{74.6796,36.2955,-91.9498}});
        addLine({{74.6796,36.2955,-91.9498},{78.1084,30,-100}});
        addLine({{69.9568,-36.9996,-100},{36.2601,-36.9996,-100}});
        addLine({{36.2601,-36.9996,-100},{32.5586,-46.2169,-130.47}});
        addLine({{32.5586,-46.2169,-130.47},{73.6582,-46.2169,-130.47}});
        addLine({{73.6582,-46.2169,-130.47},{69.9568,-36.9996,-100}});
        addLine({{78.1084,30,0},{78.1084,30,59.9756}});
        addLine({{78.1084,30,59.9756},{78.1084,-20,59.9756}});
        addLine({{78.1084,-20,59.9756},{78.1084,-12.5102,0}});
        addLine({{78.1084,-12.5102,0},{78.1084,30,0}});
        addLine({{28.1084,-25.4164,0},{28.1084,-20,100}});
        addLine({{28.1084,-20,100},{0,-20,100}});
        addLine({{0,-20,100},{0,-25.4164,0}});
        addLine({{0,-25.4164,0},{28.1084,-25.4164,0}});
        addLine({{17.3622,70,100},{0,70,100}});
        addLine({{0,70,100},{0,29.9438,193.064}});
        addLine({{0,29.9438,193.064},{17.3622,29.9438,193.064}});
        addLine({{17.3622,29.9438,193.064},{17.3622,70,100}});
        addLine({{17.3622,70,100},{28.1084,47.9665,0}});
        addLine({{28.1084,47.9665,0},{0,47.9665,0}});
        addLine({{0,47.9665,0},{0,70,100}});
        addLine({{0,70,100},{17.3622,70,100}});
        addLine({{78.1084,30,-100},{78.1084,30,0}});
        addLine({{78.1084,30,0},{78.1084,-12.5102,0}});
        addLine({{78.1084,-12.5102,0},{78.1084,-20,-100}});
        addLine({{78.1084,-20,-100},{78.1084,30,-100}});
        addLine({{28.1084,-20,-100},{28.1084,-25.4164,0}});
        addLine({{28.1084,-25.4164,0},{0,-25.4164,0}});
        addLine({{0,-25.4164,0},{0,-20,-100}});
        addLine({{0,-20,-100},{28.1084,-20,-100}});
        addLine({{28.1084,30,-100},{28.1084,30,0}});
        addLine({{28.1084,30,0},{37.27,46.821,-13.4321}});
        addLine({{37.27,46.821,-13.4321},{37.27,46.821,-100}});
        addLine({{37.27,46.821,-100},{28.1084,30,-100}});
        addLine({{0,30,-100},{28.1084,30,-100}});
        addLine({{28.1084,30,-100},{28.1084,-20,-100}});
        addLine({{28.1084,-20,-100},{0,-20,-100}});
        addLine({{0,-20,-100},{0,30,-100}});
        addLine({{78.1084,-25.4164,0},{78.1084,-20,59.9756}});
        addLine({{78.1084,-20,59.9756},{28.1084,-20,100}});
        addLine({{28.1084,-20,100},{28.1084,-25.4164,0}});
        addLine({{28.1084,-25.4164,0},{78.1084,-25.4164,0}});
        addLine({{28.1084,30,100},{28.1084,-20,100}});
        addLine({{28.1084,-20,100},{36.9608,-11.1476,92.9138}});
        addLine({{36.9608,-11.1476,92.9138},{36.9608,21.1476,92.9138}});
        addLine({{36.9608,21.1476,92.9138},{28.1084,30,100}});
        addLine({{78.1084,30,59.9756},{78.1084,30,0}});
        addLine({{78.1084,30,0},{28.1084,30,0}});
        addLine({{28.1084,30,0},{28.1084,30,100}});
        addLine({{28.1084,30,100},{78.1084,30,59.9756}});
        addLine({{28.1084,-25.4164,0},{28.1084,-20,-100}});
        addLine({{28.1084,-20,-100},{36.2601,-36.9996,-100}});
        addLine({{36.2601,-36.9996,-100},{36.2601,-36.9996,-13.4321}});
        addLine({{36.2601,-36.9996,-13.4321},{28.1084,-25.4164,0}});
        addLine({{28.1084,30,100},{17.3622,70,100}});
        addLine({{17.3622,70,100},{17.3622,29.9438,193.064}});
        addLine({{17.3622,29.9438,193.064},{28.1084,6.3507,179.383}});
        addLine({{28.1084,6.3507,179.383},{28.1084,30,100}});
        addLine({{17.3622,70,100},{28.1084,30,100}});
        addLine({{28.1084,30,100},{28.1084,30,0}});
        addLine({{28.1084,30,0},{28.1084,47.9665,0}});
        addLine({{28.1084,47.9665,0},{17.3622,70,100}});
        addLine({{28.1084,-20,100},{28.1084,30,100}});
        addLine({{28.1084,30,100},{28.1084,6.3507,179.383}});
        addLine({{28.1084,6.3507,179.383},{28.1084,-23.1406,162.282}});
        addLine({{28.1084,-23.1406,162.282},{28.1084,-20,100}});
        addLine({{0,-20,100},{28.1084,-20,100}});
        addLine({{28.1084,-20,100},{28.1084,-23.1406,162.282}});
        addLine({{28.1084,-23.1406,162.282},{0,-23.1406,162.282}});
        addLine({{0,-23.1406,162.282},{0,-20,100}});
        addLine({{0,-23.1406,162.282},{28.1084,-23.1406,162.282}});
        addLine({{28.1084,-23.1406,162.282},{17.3451,-25.4688,223.654}});
        addLine({{17.3451,-25.4688,223.654},{0,-25.4688,223.654}});
        addLine({{0,-25.4688,223.654},{0,-23.1406,162.282}});
        addLine({{28.1084,-23.1406,162.282},{28.1084,6.3507,179.383}});
        addLine({{28.1084,6.3507,179.383},{17.3451,-0.952499,237.87}});
        addLine({{17.3451,-0.952499,237.87},{17.3451,-25.4688,223.654}});
        addLine({{17.3451,-25.4688,223.654},{28.1084,-23.1406,162.282}});
        addLine({{28.1084,30,-100},{0,30,-100}});
        addLine({{0,30,-100},{0,47.9665,0}});
        addLine({{0,47.9665,0},{28.1084,47.9665,0}});
        addLine({{28.1084,47.9665,0},{28.1084,30,-100}});
        addLine({{28.1084,30,0},{28.1084,30,-100}});
        addLine({{28.1084,30,-100},{28.1084,47.9665,0}});
        addLine({{28.1084,47.9665,0},{28.1084,30,0}});
        addLine({{28.1084,30,0},{78.1084,30,0}});
        addLine({{78.1084,30,0},{68.9468,46.821,-13.4321}});
        addLine({{68.9468,46.821,-13.4321},{37.27,46.821,-13.4321}});
        addLine({{37.27,46.821,-13.4321},{28.1084,30,0}});
        addLine({{68.9468,46.821,-13.4321},{68.9468,46.821,-100}});
        addLine({{68.9468,46.821,-100},{37.27,46.821,-100}});
        addLine({{37.27,46.821,-100},{37.27,46.821,-13.4321}});
        addLine({{37.27,46.821,-13.4321},{68.9468,46.821,-13.4321}});
        addLine({{36.2601,-36.9996,-100},{28.1084,-20,-100}});
        addLine({{28.1084,-20,-100},{22.6161,-25.4826,-130.47}});
        addLine({{22.6161,-25.4826,-130.47},{32.5586,-46.2169,-130.47}});
        addLine({{32.5586,-46.2169,-130.47},{36.2601,-36.9996,-100}});
        addLine({{69.9568,-36.9996,-100},{69.9568,-36.9996,-13.4321}});
        addLine({{69.9568,-36.9996,-13.4321},{36.2601,-36.9996,-13.4321}});
        addLine({{36.2601,-36.9996,-13.4321},{36.2601,-36.9996,-100}});
        addLine({{36.2601,-36.9996,-100},{69.9568,-36.9996,-100}});
        addLine({{78.1084,-25.4164,0},{28.1084,-25.4164,0}});
        addLine({{28.1084,-25.4164,0},{36.2601,-36.9996,-13.4321}});
        addLine({{36.2601,-36.9996,-13.4321},{69.9568,-36.9996,-13.4321}});
        addLine({{69.9568,-36.9996,-13.4321},{78.1084,-25.4164,0}});
        addLine({{78.1084,-20,-100},{69.9568,-36.9996,-100}});
        addLine({{69.9568,-36.9996,-100},{73.6582,-46.2169,-130.47}});
        addLine({{73.6582,-46.2169,-130.47},{83.6008,-25.4826,-130.47}});
        addLine({{83.6008,-25.4826,-130.47},{78.1084,-20,-100}});
        addLine({{78.1084,-20,-100},{78.1084,-25.4164,0}});
        addLine({{78.1084,-25.4164,0},{69.9568,-36.9996,-13.4321}});
        addLine({{69.9568,-36.9996,-13.4321},{69.9568,-36.9996,-100}});
        addLine({{69.9568,-36.9996,-100},{78.1084,-20,-100}});
        addLine({{28.1084,6.3507,179.383},{17.3622,29.9438,193.064}});
        addLine({{17.3622,29.9438,193.064},{17.3451,-0.952499,237.87}});
        addLine({{17.3451,-0.952499,237.87},{28.1084,6.3507,179.383}});
        addLine({{17.3622,29.9438,193.064},{0,29.9438,193.064}});
        addLine({{0,29.9438,193.064},{0,-0.952499,237.87}});
        addLine({{0,-0.952499,237.87},{17.3451,-0.952499,237.87}});
        addLine({{17.3451,-0.952499,237.87},{17.3622,29.9438,193.064}});
        addLine({{0,-0.952499,237.87},{0,-25.4688,223.654}});
        addLine({{0,-25.4688,223.654},{17.3451,-25.4688,223.654}});
        addLine({{17.3451,-25.4688,223.654},{17.3451,-0.952499,237.87}});
        addLine({{17.3451,-0.952499,237.87},{0,-0.952499,237.87}});
        addLine({{68.9468,46.821,-100},{78.1084,30,-100}});
        addLine({{78.1084,30,-100},{83.6008,35.5022,-130.47}});
        addLine({{83.6008,35.5022,-130.47},{72.4264,56.0187,-130.47}});
        addLine({{72.4264,56.0187,-130.47},{68.9468,46.821,-100}});
        addLine({{37.27,46.821,-100},{68.9468,46.821,-100}});
        addLine({{68.9468,46.821,-100},{72.4264,56.0187,-130.47}});
        addLine({{72.4264,56.0187,-130.47},{33.7904,56.0187,-130.47}});
        addLine({{33.7904,56.0187,-130.47},{37.27,46.821,-100}});
        addLine({{28.1084,30,-100},{37.27,46.821,-100}});
        addLine({{37.27,46.821,-100},{33.7904,56.0187,-130.47}});
        addLine({{33.7904,56.0187,-130.47},{22.6161,35.5022,-130.47}});
        addLine({{22.6161,35.5022,-130.47},{28.1084,30,-100}});
        addLine({{28.1084,-20,-100},{28.1084,30,-100}});
        addLine({{28.1084,30,-100},{22.6161,35.5022,-130.47}});
        addLine({{22.6161,35.5022,-130.47},{22.6161,-25.4826,-130.47}});
        addLine({{22.6161,-25.4826,-130.47},{28.1084,-20,-100}});
        addLine({{78.1084,30,-100},{78.1084,-20,-100}});
        addLine({{78.1084,-20,-100},{83.6008,-25.4826,-130.47}});
        addLine({{83.6008,-25.4826,-130.47},{83.6008,35.5022,-130.47}});
        addLine({{83.6008,35.5022,-130.47},{78.1084,30,-100}});
        addLine({{83.6008,-25.4826,-130.47},{73.6582,-46.2169,-130.47}});
        addLine({{73.6582,-46.2169,-130.47},{65.4973,-25.8949,-92.3826}});
        addLine({{65.4973,-25.8949,-92.3826},{71.4914,-13.3948,-92.3826}});
        addLine({{71.4914,-13.3948,-92.3826},{83.6008,-25.4826,-130.47}});
        addLine({{32.5586,-46.2169,-130.47},{22.6161,-25.4826,-130.47}});
        addLine({{22.6161,-25.4826,-130.47},{34.7254,-13.3948,-92.3826}});
        addLine({{34.7254,-13.3948,-92.3826},{40.7195,-25.8949,-92.3826}});
        addLine({{40.7195,-25.8949,-92.3826},{32.5586,-46.2169,-130.47}});
        addLine({{73.6582,-46.2169,-130.47},{32.5586,-46.2169,-130.47}});
        addLine({{32.5586,-46.2169,-130.47},{40.7195,-25.8949,-92.3826}});
        addLine({{40.7195,-25.8949,-92.3826},{65.4973,-25.8949,-92.3826}});
        addLine({{65.4973,-25.8949,-92.3826},{73.6582,-46.2169,-130.47}});
        addLine({{72.4264,56.0187,-130.47},{83.6008,35.5022,-130.47}});
        addLine({{83.6008,35.5022,-130.47},{71.4914,23.3712,-92.3826}});
        addLine({{71.4914,23.3712,-92.3826},{64.7547,35.74,-92.3826}});
        addLine({{64.7547,35.74,-92.3826},{72.4264,56.0187,-130.47}});
        addLine({{33.7904,56.0187,-130.47},{72.4264,56.0187,-130.47}});
        addLine({{72.4264,56.0187,-130.47},{64.7547,35.74,-92.3826}});
        addLine({{64.7547,35.74,-92.3826},{41.4621,35.74,-92.3826}});
        addLine({{41.4621,35.74,-92.3826},{33.7904,56.0187,-130.47}});
        addLine({{22.6161,35.5022,-130.47},{33.7904,56.0187,-130.47}});
        addLine({{33.7904,56.0187,-130.47},{41.4621,35.74,-92.3826}});
        addLine({{41.4621,35.74,-92.3826},{34.7254,23.3712,-92.3826}});
        addLine({{34.7254,23.3712,-92.3826},{22.6161,35.5022,-130.47}});
        addLine({{83.6008,35.5022,-130.47},{83.6008,-25.4826,-130.47}});
        addLine({{83.6008,-25.4826,-130.47},{71.4914,-13.3948,-92.3826}});
        addLine({{71.4914,-13.3948,-92.3826},{71.4914,23.3712,-92.3826}});
        addLine({{71.4914,23.3712,-92.3826},{83.6008,35.5022,-130.47}});
        addLine({{22.6161,-25.4826,-130.47},{22.6161,35.5022,-130.47}});
        addLine({{22.6161,35.5022,-130.47},{34.7254,23.3712,-92.3826}});
        addLine({{34.7254,23.3712,-92.3826},{34.7254,-13.3948,-92.3826}});
        addLine({{34.7254,-13.3948,-92.3826},{22.6161,-25.4826,-130.47}});
        addLine({{34.7254,23.3712,-92.3826},{41.4621,35.74,-92.3826}});
        addLine({{41.4621,35.74,-92.3826},{64.7547,35.74,-92.3826}});
        addLine({{64.7547,35.74,-92.3826},{71.4914,23.3712,-92.3826}});
        addLine({{71.4914,23.3712,-92.3826},{71.4914,-13.3948,-92.3826}});
        addLine({{71.4914,-13.3948,-92.3826},{65.4973,-25.8949,-92.3826}});
        addLine({{65.4973,-25.8949,-92.3826},{40.7195,-25.8949,-92.3826}});
        addLine({{40.7195,-25.8949,-92.3826},{34.7254,-13.3948,-92.3826}});
        addLine({{34.7254,-13.3948,-92.3826},{34.7254,23.3712,-92.3826}});
        addLine({{159.759,-33.2472,16.3479},{159.759,-37.0105,-29.8727}});
        addLine({{159.759,-37.0105,-29.8727},{241.411,-48.6047,-59.7455}});
        addLine({{241.411,-48.6047,-59.7455},{241.411,-46.4944,-27.2798}});
        addLine({{241.411,-46.4944,-27.2798},{159.759,-33.2472,16.3479}});
        addLine({{159.759,-37.0105,-29.8727},{127.571,-33.2472,-133.18}});
        addLine({{127.571,-33.2472,-133.18},{241.411,-46.4944,-113.877}});
        addLine({{241.411,-46.4944,-113.877},{241.411,-48.6047,-59.7455}});
        addLine({{241.411,-48.6047,-59.7455},{159.759,-37.0105,-29.8727}});
        addLine({{159.759,-28.0432,-29.8727},{159.759,-33.2472,16.3479}});
        addLine({{159.759,-33.2472,16.3479},{241.411,-46.4944,-27.2798}});
        addLine({{241.411,-46.4944,-27.2798},{241.411,-43.5763,-59.7455}});
        addLine({{241.411,-43.5763,-59.7455},{159.759,-28.0432,-29.8727}});
        addLine({{127.571,-33.2472,-133.18},{159.759,-28.0432,-29.8727}});
        addLine({{159.759,-28.0432,-29.8727},{241.411,-43.5763,-59.7455}});
        addLine({{241.411,-43.5763,-59.7455},{241.411,-46.4944,-113.877}});
        addLine({{241.411,-46.4944,-113.877},{127.571,-33.2472,-133.18}});
        addLine({{241.411,-48.6047,-59.7455},{241.411,-46.4944,-113.877}});
        addLine({{241.411,-46.4944,-113.877},{241.411,-43.5763,-59.7455}});
        addLine({{241.411,-43.5763,-59.7455},{241.411,-46.4944,-27.2798}});
        addLine({{241.411,-46.4944,-27.2798},{241.411,-48.6047,-59.7455}});
        addLine({{78.1084,30,0},{78.1084,30,-100}});
        addLine({{78.1084,30,-100},{74.6796,36.2955,-91.9498}});
        addLine({{74.6796,36.2955,-91.9498},{73.5276,36.9326,-20.6404}});
        addLine({{73.5276,36.9326,-20.6404},{78.1084,30,0}});
        addLine({{74.6796,36.2955,-91.9498},{72.3757,40.5256,-91.9498}});
        addLine({{72.3757,40.5256,-91.9498},{155.666,86.3546,-149.38}});
        addLine({{155.666,86.3546,-149.38},{156.882,84.1218,-149.38}});
        addLine({{156.882,84.1218,-149.38},{74.6796,36.2955,-91.9498}});
        addLine({{73.5276,36.9326,-20.6404},{74.6796,36.2955,-91.9498}});
        addLine({{74.6796,36.2955,-91.9498},{156.882,84.1218,-149.38}});
        addLine({{156.882,84.1218,-149.38},{156.882,84.1218,-105.706}});
        addLine({{156.882,84.1218,-105.706},{73.5276,36.9326,-20.6404}});
        addLine({{68.9468,46.821,-13.4321},{78.1084,30,0}});
        addLine({{78.1084,30,0},{73.5276,36.9326,-20.6404}});
        addLine({{73.5276,36.9326,-20.6404},{68.9468,46.821,-13.4321}});
        addLine({{68.9468,46.821,-100},{68.9468,46.821,-13.4321}});
        addLine({{68.9468,46.821,-13.4321},{73.5276,36.9326,-20.6404}});
        addLine({{73.5276,36.9326,-20.6404},{72.3757,40.5256,-91.9498}});
        addLine({{72.3757,40.5256,-91.9498},{68.9468,46.821,-100}});
        addLine({{78.1084,-20,59.9756},{78.1084,-25.4164,0}});
        addLine({{78.1084,-25.4164,0},{159.759,-37.0105,-29.8727}});
        addLine({{159.759,-37.0105,-29.8727},{159.759,-33.2472,16.3479}});
        addLine({{159.759,-33.2472,16.3479},{78.1084,-20,59.9756}});
        addLine({{78.1084,-25.4164,0},{78.1084,-20,-100}});
        addLine({{78.1084,-20,-100},{127.571,-33.2472,-133.18}});
        addLine({{127.571,-33.2472,-133.18},{159.759,-37.0105,-29.8727}});
        addLine({{159.759,-37.0105,-29.8727},{78.1084,-25.4164,0}});
        addLine({{78.1084,-12.5102,0},{78.1084,-20,59.9756}});
        addLine({{78.1084,-20,59.9756},{159.759,-33.2472,16.3479}});
        addLine({{159.759,-33.2472,16.3479},{159.759,-28.0432,-29.8727}});
        addLine({{159.759,-28.0432,-29.8727},{78.1084,-12.5102,0}});
        addLine({{78.1084,-20,-100},{78.1084,-12.5102,0}});
        addLine({{78.1084,-12.5102,0},{159.759,-28.0432,-29.8727}});
        addLine({{159.759,-28.0432,-29.8727},{127.571,-33.2472,-133.18}});
        addLine({{127.571,-33.2472,-133.18},{78.1084,-20,-100}});
        addLine({{36.9608,21.1476,92.9138},{36.9608,-11.1476,92.9138}});
        addLine({{36.9608,-11.1476,92.9138},{36.9608,-11.1476,73.9688}});
        addLine({{36.9608,-11.1476,73.9688},{36.9608,21.1476,73.9688}});
        addLine({{36.9608,21.1476,73.9688},{36.9608,21.1476,92.9138}});
        addLine({{28.1084,-20,100},{78.1084,-20,59.9756}});
        addLine({{78.1084,-20,59.9756},{69.2561,-11.1476,67.0618}});
        addLine({{69.2561,-11.1476,67.0618},{36.9608,-11.1476,92.9138}});
        addLine({{36.9608,-11.1476,92.9138},{28.1084,-20,100}});
        addLine({{78.1084,-20,59.9756},{78.1084,30,59.9756}});
        addLine({{78.1084,30,59.9756},{69.2561,21.1476,67.0618}});
        addLine({{69.2561,21.1476,67.0618},{69.2561,-11.1476,67.0618}});
        addLine({{69.2561,-11.1476,67.0618},{78.1084,-20,59.9756}});
        addLine({{78.1084,30,59.9756},{28.1084,30,100}});
        addLine({{28.1084,30,100},{36.9608,21.1476,92.9138}});
        addLine({{36.9608,21.1476,92.9138},{69.2561,21.1476,67.0618}});
        addLine({{69.2561,21.1476,67.0618},{78.1084,30,59.9756}});
        addLine({{36.9608,-11.1476,92.9138},{69.2561,-11.1476,67.0618}});
        addLine({{69.2561,-11.1476,67.0618},{69.2561,-11.1476,48.1168}});
        addLine({{69.2561,-11.1476,48.1168},{36.9608,-11.1476,73.9688}});
        addLine({{36.9608,-11.1476,73.9688},{36.9608,-11.1476,92.9138}});
        addLine({{69.2561,-11.1476,67.0618},{69.2561,21.1476,67.0618}});
        addLine({{69.2561,21.1476,67.0618},{69.2561,21.1476,48.1168}});
        addLine({{69.2561,21.1476,48.1168},{69.2561,-11.1476,48.1168}});
        addLine({{69.2561,-11.1476,48.1168},{69.2561,-11.1476,67.0618}});
        addLine({{69.2561,21.1476,67.0618},{36.9608,21.1476,92.9138}});
        addLine({{36.9608,21.1476,92.9138},{36.9608,21.1476,73.9688}});
        addLine({{36.9608,21.1476,73.9688},{69.2561,21.1476,48.1168}});
        addLine({{69.2561,21.1476,48.1168},{69.2561,21.1476,67.0618}});
        addLine({{69.2561,21.1476,48.1168},{36.9608,21.1476,73.9688}});
        addLine({{36.9608,21.1476,73.9688},{36.9608,-11.1476,73.9688}});
        addLine({{36.9608,-11.1476,73.9688},{69.2561,-11.1476,48.1168}});
        addLine({{69.2561,-11.1476,48.1168},{69.2561,21.1476,48.1168}});
        addLine({{72.3757,40.5256,-91.9498},{73.5276,36.9326,-20.6404}});
        addLine({{73.5276,36.9326,-20.6404},{156.882,84.1218,-105.706}});
        addLine({{156.882,84.1218,-105.706},{155.666,86.3546,-149.38}});
        addLine({{155.666,86.3546,-149.38},{72.3757,40.5256,-91.9498}});
        addLine({{156.882,84.1218,-149.38},{155.666,86.3546,-149.38}});
        addLine({{155.666,86.3546,-149.38},{156.882,84.1218,-105.706}});
        addLine({{156.882,84.1218,-105.706},{156.882,84.1218,-149.38}});
        addLine({{-78.1084,30,-100},{-74.6796,36.2955,-91.9498}});
        addLine({{-74.6796,36.2955,-91.9498},{-72.3757,40.5256,-91.9498}});
        addLine({{-72.3757,40.5256,-91.9498},{-68.9468,46.821,-100}});
        addLine({{-68.9468,46.821,-100},{-78.1084,30,-100}});
        addLine({{-69.9568,-36.9996,-100},{-73.6582,-46.2169,-130.47}});
        addLine({{-73.6582,-46.2169,-130.47},{-32.5586,-46.2169,-130.47}});
        addLine({{-32.5586,-46.2169,-130.47},{-36.2601,-36.9996,-100}});
        addLine({{-36.2601,-36.9996,-100},{-69.9568,-36.9996,-100}});
        addLine({{-78.1084,30,0},{-78.1084,-12.5102,0}});
        addLine({{-78.1084,-12.5102,0},{-78.1084,-20,59.9756}});
        addLine({{-78.1084,-20,59.9756},{-78.1084,30,59.9756}});
        addLine({{-78.1084,30,59.9756},{-78.1084,30,0}});
        addLine({{-28.1084,-25.4164,0},{0,-25.4164,0}});
        addLine({{0,-25.4164,0},{0,-20,100}});
        addLine({{0,-20,100},{-28.1084,-20,100}});
        addLine({{-28.1084,-20,100},{-28.1084,-25.4164,0}});
        addLine({{-17.3622,70,100},{-17.3622,29.9438,193.064}});
        addLine({{-17.3622,29.9438,193.064},{0,29.9438,193.064}});
        addLine({{0,29.9438,193.064},{0,70,100}});
        addLine({{0,70,100},{-17.3622,70,100}});
        addLine({{-17.3622,70,100},{0,70,100}});
        addLine({{0,70,100},{0,47.9665,0}});
        addLine({{0,47.9665,0},{-28.1084,47.9665,0}});
        addLine({{-28.1084,47.9665,0},{-17.3622,70,100}});
        addLine({{-78.1084,30,-100},{-78.1084,-20,-100}});
        addLine({{-78.1084,-20,-100},{-78.1084,-12.5102,0}});
        addLine({{-78.1084,-12.5102,0},{-78.1084,30,0}});
        addLine({{-78.1084,30,0},{-78.1084,30,-100}});
        addLine({{-28.1084,-20,-100},{0,-20,-100}});
        addLine({{0,-20,-100},{0,-25.4164,0}});
        addLine({{0,-25.4164,0},{-28.1084,-25.4164,0}});
        addLine({{-28.1084,-25.4164,0},{-28.1084,-20,-100}});
        addLine({{-28.1084,30,-100},{-37.27,46.821,-100}});
        addLine({{-37.27,46.821,-100},{-37.27,46.821,-13.4321}});
        addLine({{-37.27,46.821,-13.4321},{-28.1084,30,0}});
        addLine({{-28.1084,30,0},{-28.1084,30,-100}});
        addLine({{0,30,-100},{0,-20,-100}});
        addLine({{0,-20,-100},{-28.1084,-20,-100}});
        addLine({{-28.1084,-20,-100},{-28.1084,30,-100}});
        addLine({{-28.1084,30,-100},{0,30,-100}});
        addLine({{-78.1084,-25.4164,0},{-28.1084,-25.4164,0}});
        addLine({{-28.1084,-25.4164,0},{-28.1084,-20,100}});
        addLine({{-28.1084,-20,100},{-78.1084,-20,59.9756}});
        addLine({{-78.1084,-20,59.9756},{-78.1084,-25.4164,0}});
        addLine({{-28.1084,30,100},{-36.9608,21.1476,92.9138}});
        addLine({{-36.9608,21.1476,92.9138},{-36.9608,-11.1476,92.9138}});
        addLine({{-36.9608,-11.1476,92.9138},{-28.1084,-20,100}});
        addLine({{-28.1084,-20,100},{-28.1084,30,100}});
        addLine({{-78.1084,30,59.9756},{-28.1084,30,100}});
        addLine({{-28.1084,30,100},{-28.1084,30,0}});
        addLine({{-28.1084,30,0},{-78.1084,30,0}});
        addLine({{-78.1084,30,0},{-78.1084,30,59.9756}});
        addLine({{-28.1084,-25.4164,0},{-36.2601,-36.9996,-13.4321}});
        addLine({{-36.2601,-36.9996,-13.4321},{-36.2601,-36.9996,-100}});
        addLine({{-36.2601,-36.9996,-100},{-28.1084,-20,-100}});
        addLine({{-28.1084,-20,-100},{-28.1084,-25.4164,0}});
        addLine({{-28.1084,30,100},{-28.1084,6.3507,179.383}});
        addLine({{-28.1084,6.3507,179.383},{-17.3622,29.9438,193.064}});
        addLine({{-17.3622,29.9438,193.064},{-17.3622,70,100}});
        addLine({{-17.3622,70,100},{-28.1084,30,100}});
        addLine({{-17.3622,70,100},{-28.1084,47.9665,0}});
        addLine({{-28.1084,47.9665,0},{-28.1084,30,0}});
        addLine({{-28.1084,30,0},{-28.1084,30,100}});
        addLine({{-28.1084,30,100},{-17.3622,70,100}});
        addLine({{-28.1084,-20,100},{-28.1084,-23.1406,162.282}});
        addLine({{-28.1084,-23.1406,162.282},{-28.1084,6.3507,179.383}});
        addLine({{-28.1084,6.3507,179.383},{-28.1084,30,100}});
        addLine({{-28.1084,30,100},{-28.1084,-20,100}});
        addLine({{0,-20,100},{0,-23.1406,162.282}});
        addLine({{0,-23.1406,162.282},{-28.1084,-23.1406,162.282}});
        addLine({{-28.1084,-23.1406,162.282},{-28.1084,-20,100}});
        addLine({{-28.1084,-20,100},{0,-20,100}});
        addLine({{0,-23.1406,162.282},{0,-25.4688,223.654}});
        addLine({{0,-25.4688,223.654},{-17.3451,-25.4688,223.654}});
        addLine({{-17.3451,-25.4688,223.654},{-28.1084,-23.1406,162.282}});
        addLine({{-28.1084,-23.1406,162.282},{0,-23.1406,162.282}});
        addLine({{-28.1084,-23.1406,162.282},{-17.3451,-25.4688,223.654}});
        addLine({{-17.3451,-25.4688,223.654},{-17.3451,-0.952499,237.87}});
        addLine({{-17.3451,-0.952499,237.87},{-28.1084,6.3507,179.383}});
        addLine({{-28.1084,6.3507,179.383},{-28.1084,-23.1406,162.282}});
        addLine({{-28.1084,30,-100},{-28.1084,47.9665,0}});
        addLine({{-28.1084,47.9665,0},{0,47.9665,0}});
        addLine({{0,47.9665,0},{0,30,-100}});
        addLine({{0,30,-100},{-28.1084,30,-100}});
        addLine({{-28.1084,30,0},{-28.1084,47.9665,0}});
        addLine({{-28.1084,47.9665,0},{-28.1084,30,-100}});
        addLine({{-28.1084,30,-100},{-28.1084,30,0}});
        addLine({{-28.1084,30,0},{-37.27,46.821,-13.4321}});
        addLine({{-37.27,46.821,-13.4321},{-68.9468,46.821,-13.4321}});
        addLine({{-68.9468,46.821,-13.4321},{-78.1084,30,0}});
        addLine({{-78.1084,30,0},{-28.1084,30,0}});
        addLine({{-68.9468,46.821,-13.4321},{-37.27,46.821,-13.4321}});
        addLine({{-37.27,46.821,-13.4321},{-37.27,46.821,-100}});
        addLine({{-37.27,46.821,-100},{-68.9468,46.821,-100}});
        addLine({{-68.9468,46.821,-100},{-68.9468,46.821,-13.4321}});
        addLine({{-36.2601,-36.9996,-100},{-32.5586,-46.2169,-130.47}});
        addLine({{-32.5586,-46.2169,-130.47},{-22.6161,-25.4826,-130.47}});
        addLine({{-22.6161,-25.4826,-130.47},{-28.1084,-20,-100}});
        addLine({{-28.1084,-20,-100},{-36.2601,-36.9996,-100}});
        addLine({{-69.9568,-36.9996,-100},{-36.2601,-36.9996,-100}});
        addLine({{-36.2601,-36.9996,-100},{-36.2601,-36.9996,-13.4321}});
        addLine({{-36.2601,-36.9996,-13.4321},{-69.9568,-36.9996,-13.4321}});
        addLine({{-69.9568,-36.9996,-13.4321},{-69.9568,-36.9996,-100}});
        addLine({{-78.1084,-25.4164,0},{-69.9568,-36.9996,-13.4321}});
        addLine({{-69.9568,-36.9996,-13.4321},{-36.2601,-36.9996,-13.4321}});
        addLine({{-36.2601,-36.9996,-13.4321},{-28.1084,-25.4164,0}});
        addLine({{-28.1084,-25.4164,0},{-78.1084,-25.4164,0}});
        addLine({{-78.1084,-20,-100},{-83.6008,-25.4826,-130.47}});
        addLine({{-83.6008,-25.4826,-130.47},{-73.6582,-46.2169,-130.47}});
        addLine({{-73.6582,-46.2169,-130.47},{-69.9568,-36.9996,-100}});
        addLine({{-69.9568,-36.9996,-100},{-78.1084,-20,-100}});
        addLine({{-78.1084,-20,-100},{-69.9568,-36.9996,-100}});
        addLine({{-69.9568,-36.9996,-100},{-69.9568,-36.9996,-13.4321}});
        addLine({{-69.9568,-36.9996,-13.4321},{-78.1084,-25.4164,0}});
        addLine({{-78.1084,-25.4164,0},{-78.1084,-20,-100}});
        addLine({{-28.1084,6.3507,179.383},{-17.3451,-0.952499,237.87}});
        addLine({{-17.3451,-0.952499,237.87},{-17.3622,29.9438,193.064}});
        addLine({{-17.3622,29.9438,193.064},{-28.1084,6.3507,179.383}});
        addLine({{-17.3622,29.9438,193.064},{-17.3451,-0.952499,237.87}});
        addLine({{-17.3451,-0.952499,237.87},{0,-0.952499,237.87}});
        addLine({{0,-0.952499,237.87},{0,29.9438,193.064}});
        addLine({{0,29.9438,193.064},{-17.3622,29.9438,193.064}});
        addLine({{0,-0.952499,237.87},{-17.3451,-0.952499,237.87}});
        addLine({{-17.3451,-0.952499,237.87},{-17.3451,-25.4688,223.654}});
        addLine({{-17.3451,-25.4688,223.654},{0,-25.4688,223.654}});
        addLine({{0,-25.4688,223.654},{0,-0.952499,237.87}});
        addLine({{-68.9468,46.821,-100},{-72.4264,56.0187,-130.47}});
        addLine({{-72.4264,56.0187,-130.47},{-83.6008,35.5022,-130.47}});
        addLine({{-83.6008,35.5022,-130.47},{-78.1084,30,-100}});
        addLine({{-78.1084,30,-100},{-68.9468,46.821,-100}});
        addLine({{-37.27,46.821,-100},{-33.7904,56.0187,-130.47}});
        addLine({{-33.7904,56.0187,-130.47},{-72.4264,56.0187,-130.47}});
        addLine({{-72.4264,56.0187,-130.47},{-68.9468,46.821,-100}});
        addLine({{-68.9468,46.821,-100},{-37.27,46.821,-100}});
        addLine({{-28.1084,30,-100},{-22.6161,35.5022,-130.47}});
        addLine({{-22.6161,35.5022,-130.47},{-33.7904,56.0187,-130.47}});
        addLine({{-33.7904,56.0187,-130.47},{-37.27,46.821,-100}});
        addLine({{-37.27,46.821,-100},{-28.1084,30,-100}});
        addLine({{-28.1084,-20,-100},{-22.6161,-25.4826,-130.47}});
        addLine({{-22.6161,-25.4826,-130.47},{-22.6161,35.5022,-130.47}});
        addLine({{-22.6161,35.5022,-130.47},{-28.1084,30,-100}});
        addLine({{-28.1084,30,-100},{-28.1084,-20,-100}});
        addLine({{-78.1084,30,-100},{-83.6008,35.5022,-130.47}});
        addLine({{-83.6008,35.5022,-130.47},{-83.6008,-25.4826,-130.47}});
        addLine({{-83.6008,-25.4826,-130.47},{-78.1084,-20,-100}});
        addLine({{-78.1084,-20,-100},{-78.1084,30,-100}});
        addLine({{-83.6008,-25.4826,-130.47},{-71.4914,-13.3948,-92.3826}});
        addLine({{-71.4914,-13.3948,-92.3826},{-65.4973,-25.8949,-92.3826}});
        addLine({{-65.4973,-25.8949,-92.3826},{-73.6582,-46.2169,-130.47}});
        addLine({{-73.6582,-46.2169,-130.47},{-83.6008,-25.4826,-130.47}});
        addLine({{-32.5586,-46.2169,-130.47},{-40.7195,-25.8949,-92.3826}});
        addLine({{-40.7195,-25.8949,-92.3826},{-34.7254,-13.3948,-92.3826}});
        addLine({{-34.7254,-13.3948,-92.3826},{-22.6161,-25.4826,-130.47}});
        addLine({{-22.6161,-25.4826,-130.47},{-32.5586,-46.2169,-130.47}});
        addLine({{-73.6582,-46.2169,-130.47},{-65.4973,-25.8949,-92.3826}});
        addLine({{-65.4973,-25.8949,-92.3826},{-40.7195,-25.8949,-92.3826}});
        addLine({{-40.7195,-25.8949,-92.3826},{-32.5586,-46.2169,-130.47}});
        addLine({{-32.5586,-46.2169,-130.47},{-73.6582,-46.2169,-130.47}});
        addLine({{-72.4264,56.0187,-130.47},{-64.7547,35.74,-92.3826}});
        addLine({{-64.7547,35.74,-92.3826},{-71.4914,23.3712,-92.3826}});
        addLine({{-71.4914,23.3712,-92.3826},{-83.6008,35.5022,-130.47}});
        addLine({{-83.6008,35.5022,-130.47},{-72.4264,56.0187,-130.47}});
        addLine({{-33.7904,56.0187,-130.47},{-41.4621,35.74,-92.3826}});
        addLine({{-41.4621,35.74,-92.3826},{-64.7547,35.74,-92.3826}});
        addLine({{-64.7547,35.74,-92.3826},{-72.4264,56.0187,-130.47}});
        addLine({{-72.4264,56.0187,-130.47},{-33.7904,56.0187,-130.47}});
        addLine({{-22.6161,35.5022,-130.47},{-34.7254,23.3712,-92.3826}});
        addLine({{-34.7254,23.3712,-92.3826},{-41.4621,35.74,-92.3826}});
        addLine({{-41.4621,35.74,-92.3826},{-33.7904,56.0187,-130.47}});
        addLine({{-33.7904,56.0187,-130.47},{-22.6161,35.5022,-130.47}});
        addLine({{-83.6008,35.5022,-130.47},{-71.4914,23.3712,-92.3826}});
        addLine({{-71.4914,23.3712,-92.3826},{-71.4914,-13.3948,-92.3826}});
        addLine({{-71.4914,-13.3948,-92.3826},{-83.6008,-25.4826,-130.47}});
        addLine({{-83.6008,-25.4826,-130.47},{-83.6008,35.5022,-130.47}});
        addLine({{-22.6161,-25.4826,-130.47},{-34.7254,-13.3948,-92.3826}});
        addLine({{-34.7254,-13.3948,-92.3826},{-34.7254,23.3712,-92.3826}});
        addLine({{-34.7254,23.3712,-92.3826},{-22.6161,35.5022,-130.47}});
        addLine({{-22.6161,35.5022,-130.47},{-22.6161,-25.4826,-130.47}});
        addLine({{-34.7254,23.3712,-92.3826},{-34.7254,-13.3948,-92.3826}});
        addLine({{-34.7254,-13.3948,-92.3826},{-40.7195,-25.8949,-92.3826}});
        addLine({{-40.7195,-25.8949,-92.3826},{-65.4973,-25.8949,-92.3826}});
        addLine({{-65.4973,-25.8949,-92.3826},{-71.4914,-13.3948,-92.3826}});
        addLine({{-71.4914,-13.3948,-92.3826},{-71.4914,23.3712,-92.3826}});
        addLine({{-71.4914,23.3712,-92.3826},{-64.7547,35.74,-92.3826}});
        addLine({{-64.7547,35.74,-92.3826},{-41.4621,35.74,-92.3826}});
        addLine({{-41.4621,35.74,-92.3826},{-34.7254,23.3712,-92.3826}});
        addLine({{-159.759,-33.2472,16.3479},{-241.411,-46.4944,-27.2798}});
        addLine({{-241.411,-46.4944,-27.2798},{-241.411,-48.6047,-59.7455}});
        addLine({{-241.411,-48.6047,-59.7455},{-159.759,-37.0105,-29.8727}});
        addLine({{-159.759,-37.0105,-29.8727},{-159.759,-33.2472,16.3479}});
        addLine({{-159.759,-37.0105,-29.8727},{-241.411,-48.6047,-59.7455}});
        addLine({{-241.411,-48.6047,-59.7455},{-241.411,-46.4944,-113.877}});
        addLine({{-241.411,-46.4944,-113.877},{-127.571,-33.2472,-133.18}});
        addLine({{-127.571,-33.2472,-133.18},{-159.759,-37.0105,-29.8727}});
        addLine({{-159.759,-28.0432,-29.8727},{-241.411,-43.5763,-59.7455}});
        addLine({{-241.411,-43.5763,-59.7455},{-241.411,-46.4944,-27.2798}});
        addLine({{-241.411,-46.4944,-27.2798},{-159.759,-33.2472,16.3479}});
        addLine({{-159.759,-33.2472,16.3479},{-159.759,-28.0432,-29.8727}});
        addLine({{-127.571,-33.2472,-133.18},{-241.411,-46.4944,-113.877}});
        addLine({{-241.411,-46.4944,-113.877},{-241.411,-43.5763,-59.7455}});
        addLine({{-241.411,-43.5763,-59.7455},{-159.759,-28.0432,-29.8727}});
        addLine({{-159.759,-28.0432,-29.8727},{-127.571,-33.2472,-133.18}});
        addLine({{-241.411,-48.6047,-59.7455},{-241.411,-46.4944,-27.2798}});
        addLine({{-241.411,-46.4944,-27.2798},{-241.411,-43.5763,-59.7455}});
        addLine({{-241.411,-43.5763,-59.7455},{-241.411,-46.4944,-113.877}});
        addLine({{-241.411,-46.4944,-113.877},{-241.411,-48.6047,-59.7455}});
        addLine({{-78.1084,30,0},{-73.5276,36.9326,-20.6404}});
        addLine({{-73.5276,36.9326,-20.6404},{-74.6796,36.2955,-91.9498}});
        addLine({{-74.6796,36.2955,-91.9498},{-78.1084,30,-100}});
        addLine({{-78.1084,30,-100},{-78.1084,30,0}});
        addLine({{-74.6796,36.2955,-91.9498},{-156.882,84.1218,-149.38}});
        addLine({{-156.882,84.1218,-149.38},{-155.666,86.3546,-149.38}});
        addLine({{-155.666,86.3546,-149.38},{-72.3757,40.5256,-91.9498}});
        addLine({{-72.3757,40.5256,-91.9498},{-74.6796,36.2955,-91.9498}});
        addLine({{-73.5276,36.9326,-20.6404},{-156.882,84.1218,-105.706}});
        addLine({{-156.882,84.1218,-105.706},{-156.882,84.1218,-149.38}});
        addLine({{-156.882,84.1218,-149.38},{-74.6796,36.2955,-91.9498}});
        addLine({{-74.6796,36.2955,-91.9498},{-73.5276,36.9326,-20.6404}});
        addLine({{-68.9468,46.821,-13.4321},{-73.5276,36.9326,-20.6404}});
        addLine({{-73.5276,36.9326,-20.6404},{-78.1084,30,0}});
        addLine({{-78.1084,30,0},{-68.9468,46.821,-13.4321}});
        addLine({{-68.9468,46.821,-100},{-72.3757,40.5256,-91.9498}});
        addLine({{-72.3757,40.5256,-91.9498},{-73.5276,36.9326,-20.6404}});
        addLine({{-73.5276,36.9326,-20.6404},{-68.9468,46.821,-13.4321}});
        addLine({{-68.9468,46.821,-13.4321},{-68.9468,46.821,-100}});
        addLine({{-78.1084,-20,59.9756},{-159.759,-33.2472,16.3479}});
        addLine({{-159.759,-33.2472,16.3479},{-159.759,-37.0105,-29.8727}});
        addLine({{-159.759,-37.0105,-29.8727},{-78.1084,-25.4164,0}});
        addLine({{-78.1084,-25.4164,0},{-78.1084,-20,59.9756}});
        addLine({{-78.1084,-25.4164,0},{-159.759,-37.0105,-29.8727}});
        addLine({{-159.759,-37.0105,-29.8727},{-127.571,-33.2472,-133.18}});
        addLine({{-127.571,-33.2472,-133.18},{-78.1084,-20,-100}});
        addLine({{-78.1084,-20,-100},{-78.1084,-25.4164,0}});
        addLine({{-78.1084,-12.5102,0},{-159.759,-28.0432,-29.8727}});
        addLine({{-159.759,-28.0432,-29.8727},{-159.759,-33.2472,16.3479}});
        addLine({{-159.759,-33.2472,16.3479},{-78.1084,-20,59.9756}});
        addLine({{-78.1084,-20,59.9756},{-78.1084,-12.5102,0}});
        addLine({{-78.1084,-20,-100},{-127.571,-33.2472,-133.18}});
        addLine({{-127.571,-33.2472,-133.18},{-159.759,-28.0432,-29.8727}});
        addLine({{-159.759,-28.0432,-29.8727},{-78.1084,-12.5102,0}});
        addLine({{-78.1084,-12.5102,0},{-78.1084,-20,-100}});
        addLine({{-36.9608,21.1476,92.9138},{-36.9608,21.1476,73.9688}});
        addLine({{-36.9608,21.1476,73.9688},{-36.9608,-11.1476,73.9688}});
        addLine({{-36.9608,-11.1476,73.9688},{-36.9608,-11.1476,92.9138}});
        addLine({{-36.9608,-11.1476,92.9138},{-36.9608,21.1476,92.9138}});
        addLine({{-28.1084,-20,100},{-36.9608,-11.1476,92.9138}});
        addLine({{-36.9608,-11.1476,92.9138},{-69.2561,-11.1476,67.0618}});
        addLine({{-69.2561,-11.1476,67.0618},{-78.1084,-20,59.9756}});
        addLine({{-78.1084,-20,59.9756},{-28.1084,-20,100}});
        addLine({{-78.1084,-20,59.9756},{-69.2561,-11.1476,67.0618}});
        addLine({{-69.2561,-11.1476,67.0618},{-69.2561,21.1476,67.0618}});
        addLine({{-69.2561,21.1476,67.0618},{-78.1084,30,59.9756}});
        addLine({{-78.1084,30,59.9756},{-78.1084,-20,59.9756}});
        addLine({{-78.1084,30,59.9756},{-69.2561,21.1476,67.0618}});
        addLine({{-69.2561,21.1476,67.0618},{-36.9608,21.1476,92.9138}});
        addLine({{-36.9608,21.1476,92.9138},{-28.1084,30,100}});
        addLine({{-28.1084,30,100},{-78.1084,30,59.9756}});
        addLine({{-36.9608,-11.1476,92.9138},{-36.9608,-11.1476,73.9688}});
        addLine({{-36.9608,-11.1476,73.9688},{-69.2561,-11.1476,48.1168}});
        addLine({{-69.2561,-11.1476,48.1168},{-69.2561,-11.1476,67.0618}});
        addLine({{-69.2561,-11.1476,67.0618},{-36.9608,-11.1476,92.9138}});
        addLine({{-69.2561,-11.1476,67.0618},{-69.2561,-11.1476,48.1168}});
        addLine({{-69.2561,-11.1476,48.1168},{-69.2561,21.1476,48.1168}});
        addLine({{-69.2561,21.1476,48.1168},{-69.2561,21.1476,67.0618}});
        addLine({{-69.2561,21.1476,67.0618},{-69.2561,-11.1476,67.0618}});
        addLine({{-69.2561,21.1476,67.0618},{-69.2561,21.1476,48.1168}});
        addLine({{-69.2561,21.1476,48.1168},{-36.9608,21.1476,73.9688}});
        addLine({{-36.9608,21.1476,73.9688},{-36.9608,21.1476,92.9138}});
        addLine({{-36.9608,21.1476,92.9138},{-69.2561,21.1476,67.0618}});
        addLine({{-69.2561,21.1476,48.1168},{-69.2561,-11.1476,48.1168}});
        addLine({{-69.2561,-11.1476,48.1168},{-36.9608,-11.1476,73.9688}});
        addLine({{-36.9608,-11.1476,73.9688},{-36.9608,21.1476,73.9688}});
        addLine({{-36.9608,21.1476,73.9688},{-69.2561,21.1476,48.1168}});
        addLine({{-72.3757,40.5256,-91.9498},{-155.666,86.3546,-149.38}});
        addLine({{-155.666,86.3546,-149.38},{-156.882,84.1218,-105.706}});
        addLine({{-156.882,84.1218,-105.706},{-73.5276,36.9326,-20.6404}});
        addLine({{-73.5276,36.9326,-20.6404},{-72.3757,40.5256,-91.9498}});
        addLine({{-156.882,84.1218,-149.38},{-156.882,84.1218,-105.706}});
        addLine({{-156.882,84.1218,-105.706},{-155.666,86.3546,-149.38}});
        addLine({{-155.666,86.3546,-149.38},{-156.882,84.1218,-149.38}});
    }

    void spaceship::transform(const models::Matrix &m) {
        object::transform(m);
    }

    void spaceship::shoot() {
        auto bullet {std::make_unique<objects::bullet>(origin_, *this)};
        world_.addObject(std::move(bullet));
    }
}