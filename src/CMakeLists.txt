target_sources(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/app.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/view/view.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/view/camera.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/objects/object.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/objects/cube.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/objects/pyramid.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/objects/spaceship.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/objects/bullet.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/models/line3d.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/models/matrix.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/models/point3d.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/models/world.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/input/key_handler.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/models"
    "${CMAKE_CURRENT_LIST_DIR}/objects"
    "${CMAKE_CURRENT_LIST_DIR}/tests"
    "${CMAKE_CURRENT_LIST_DIR}/utils"
    "${CMAKE_CURRENT_LIST_DIR}/view"
    "${CMAKE_CURRENT_LIST_DIR}/config"
    "${CMAKE_CURRENT_LIST_DIR}/input"
)