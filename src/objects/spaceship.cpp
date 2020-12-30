#include "spaceship.h"

namespace objects {
    spaceship::spaceship(view::view& view, const models::point3d& origin)
        : object(view, origin)
    {
        addLine({{78.1084,100,-100},{68.9468,116.821,-100}});
        addLine({{68.9468,116.821,-100},{72.3757,110.526,-91.9498}});
        addLine({{72.3757,110.526,-91.9498},{74.6796,106.296,-91.9498}});
        addLine({{74.6796,106.296,-91.9498},{78.1084,100,-100}});
        addLine({{69.9568,33.0004,-100},{36.2601,33.0004,-100}});
        addLine({{36.2601,33.0004,-100},{32.5586,23.7831,-130.47}});
        addLine({{32.5586,23.7831,-130.47},{73.6582,23.7831,-130.47}});
        addLine({{73.6582,23.7831,-130.47},{69.9568,33.0004,-100}});
        addLine({{78.1084,100,0},{78.1084,100,59.9756}});
        addLine({{78.1084,100,59.9756},{78.1084,50,59.9756}});
        addLine({{78.1084,50,59.9756},{78.1084,57.4898,0}});
        addLine({{78.1084,57.4898,0},{78.1084,100,0}});
        addLine({{28.1084,44.5836,0},{28.1084,50,100}});
        addLine({{28.1084,50,100},{0,50,100}});
        addLine({{0,50,100},{0,44.5836,0}});
        addLine({{0,44.5836,0},{28.1084,44.5836,0}});
        addLine({{17.3622,140,100},{0,140,100}});
        addLine({{0,140,100},{0,99.9438,193.064}});
        addLine({{0,99.9438,193.064},{17.3622,99.9438,193.064}});
        addLine({{17.3622,99.9438,193.064},{17.3622,140,100}});
        addLine({{17.3622,140,100},{28.1084,117.966,0}});
        addLine({{28.1084,117.966,0},{0,117.966,0}});
        addLine({{0,117.966,0},{0,140,100}});
        addLine({{0,140,100},{17.3622,140,100}});
        addLine({{78.1084,100,-100},{78.1084,100,0}});
        addLine({{78.1084,100,0},{78.1084,57.4898,0}});
        addLine({{78.1084,57.4898,0},{78.1084,50,-100}});
        addLine({{78.1084,50,-100},{78.1084,100,-100}});
        addLine({{28.1084,50,-100},{28.1084,44.5836,0}});
        addLine({{28.1084,44.5836,0},{0,44.5836,0}});
        addLine({{0,44.5836,0},{0,50,-100}});
        addLine({{0,50,-100},{28.1084,50,-100}});
        addLine({{28.1084,100,-100},{28.1084,100,0}});
        addLine({{28.1084,100,0},{37.27,116.821,-13.4321}});
        addLine({{37.27,116.821,-13.4321},{37.27,116.821,-100}});
        addLine({{37.27,116.821,-100},{28.1084,100,-100}});
        addLine({{0,100,-100},{28.1084,100,-100}});
        addLine({{28.1084,100,-100},{28.1084,50,-100}});
        addLine({{28.1084,50,-100},{0,50,-100}});
        addLine({{0,50,-100},{0,100,-100}});
        addLine({{78.1084,44.5836,0},{78.1084,50,59.9756}});
        addLine({{78.1084,50,59.9756},{28.1084,50,100}});
        addLine({{28.1084,50,100},{28.1084,44.5836,0}});
        addLine({{28.1084,44.5836,0},{78.1084,44.5836,0}});
        addLine({{28.1084,100,100},{28.1084,50,100}});
        addLine({{28.1084,50,100},{36.9608,58.8524,92.9138}});
        addLine({{36.9608,58.8524,92.9138},{36.9608,91.1476,92.9138}});
        addLine({{36.9608,91.1476,92.9138},{28.1084,100,100}});
        addLine({{78.1084,100,59.9756},{78.1084,100,0}});
        addLine({{78.1084,100,0},{28.1084,100,0}});
        addLine({{28.1084,100,0},{28.1084,100,100}});
        addLine({{28.1084,100,100},{78.1084,100,59.9756}});
        addLine({{28.1084,44.5836,0},{28.1084,50,-100}});
        addLine({{28.1084,50,-100},{36.2601,33.0004,-100}});
        addLine({{36.2601,33.0004,-100},{36.2601,33.0004,-13.4321}});
        addLine({{36.2601,33.0004,-13.4321},{28.1084,44.5836,0}});
        addLine({{28.1084,100,100},{17.3622,140,100}});
        addLine({{17.3622,140,100},{17.3622,99.9438,193.064}});
        addLine({{17.3622,99.9438,193.064},{28.1084,76.3507,179.383}});
        addLine({{28.1084,76.3507,179.383},{28.1084,100,100}});
        addLine({{17.3622,140,100},{28.1084,100,100}});
        addLine({{28.1084,100,100},{28.1084,100,0}});
        addLine({{28.1084,100,0},{28.1084,117.966,0}});
        addLine({{28.1084,117.966,0},{17.3622,140,100}});
        addLine({{28.1084,50,100},{28.1084,100,100}});
        addLine({{28.1084,100,100},{28.1084,76.3507,179.383}});
        addLine({{28.1084,76.3507,179.383},{28.1084,46.8594,162.282}});
        addLine({{28.1084,46.8594,162.282},{28.1084,50,100}});
        addLine({{0,50,100},{28.1084,50,100}});
        addLine({{28.1084,50,100},{28.1084,46.8594,162.282}});
        addLine({{28.1084,46.8594,162.282},{0,46.8594,162.282}});
        addLine({{0,46.8594,162.282},{0,50,100}});
        addLine({{0,46.8594,162.282},{28.1084,46.8594,162.282}});
        addLine({{28.1084,46.8594,162.282},{17.3451,44.5312,223.654}});
        addLine({{17.3451,44.5312,223.654},{0,44.5312,223.654}});
        addLine({{0,44.5312,223.654},{0,46.8594,162.282}});
        addLine({{28.1084,46.8594,162.282},{28.1084,76.3507,179.383}});
        addLine({{28.1084,76.3507,179.383},{17.3451,69.0475,237.87}});
        addLine({{17.3451,69.0475,237.87},{17.3451,44.5312,223.654}});
        addLine({{17.3451,44.5312,223.654},{28.1084,46.8594,162.282}});
        addLine({{28.1084,100,-100},{0,100,-100}});
        addLine({{0,100,-100},{0,117.966,0}});
        addLine({{0,117.966,0},{28.1084,117.966,0}});
        addLine({{28.1084,117.966,0},{28.1084,100,-100}});
        addLine({{28.1084,100,0},{28.1084,100,-100}});
        addLine({{28.1084,100,-100},{28.1084,117.966,0}});
        addLine({{28.1084,117.966,0},{28.1084,100,0}});
        addLine({{28.1084,100,0},{78.1084,100,0}});
        addLine({{78.1084,100,0},{68.9468,116.821,-13.4321}});
        addLine({{68.9468,116.821,-13.4321},{37.27,116.821,-13.4321}});
        addLine({{37.27,116.821,-13.4321},{28.1084,100,0}});
        addLine({{68.9468,116.821,-13.4321},{68.9468,116.821,-100}});
        addLine({{68.9468,116.821,-100},{37.27,116.821,-100}});
        addLine({{37.27,116.821,-100},{37.27,116.821,-13.4321}});
        addLine({{37.27,116.821,-13.4321},{68.9468,116.821,-13.4321}});
        addLine({{36.2601,33.0004,-100},{28.1084,50,-100}});
        addLine({{28.1084,50,-100},{22.6161,44.5174,-130.47}});
        addLine({{22.6161,44.5174,-130.47},{32.5586,23.7831,-130.47}});
        addLine({{32.5586,23.7831,-130.47},{36.2601,33.0004,-100}});
        addLine({{69.9568,33.0004,-100},{69.9568,33.0004,-13.4321}});
        addLine({{69.9568,33.0004,-13.4321},{36.2601,33.0004,-13.4321}});
        addLine({{36.2601,33.0004,-13.4321},{36.2601,33.0004,-100}});
        addLine({{36.2601,33.0004,-100},{69.9568,33.0004,-100}});
        addLine({{78.1084,44.5836,0},{28.1084,44.5836,0}});
        addLine({{28.1084,44.5836,0},{36.2601,33.0004,-13.4321}});
        addLine({{36.2601,33.0004,-13.4321},{69.9568,33.0004,-13.4321}});
        addLine({{69.9568,33.0004,-13.4321},{78.1084,44.5836,0}});
        addLine({{78.1084,50,-100},{69.9568,33.0004,-100}});
        addLine({{69.9568,33.0004,-100},{73.6582,23.7831,-130.47}});
        addLine({{73.6582,23.7831,-130.47},{83.6008,44.5174,-130.47}});
        addLine({{83.6008,44.5174,-130.47},{78.1084,50,-100}});
        addLine({{78.1084,50,-100},{78.1084,44.5836,0}});
        addLine({{78.1084,44.5836,0},{69.9568,33.0004,-13.4321}});
        addLine({{69.9568,33.0004,-13.4321},{69.9568,33.0004,-100}});
        addLine({{69.9568,33.0004,-100},{78.1084,50,-100}});
        addLine({{28.1084,76.3507,179.383},{17.3622,99.9438,193.064}});
        addLine({{17.3622,99.9438,193.064},{17.3451,69.0475,237.87}});
        addLine({{17.3451,69.0475,237.87},{28.1084,76.3507,179.383}});
        addLine({{17.3622,99.9438,193.064},{0,99.9438,193.064}});
        addLine({{0,99.9438,193.064},{0,69.0475,237.87}});
        addLine({{0,69.0475,237.87},{17.3451,69.0475,237.87}});
        addLine({{17.3451,69.0475,237.87},{17.3622,99.9438,193.064}});
        addLine({{0,69.0475,237.87},{0,44.5312,223.654}});
        addLine({{0,44.5312,223.654},{17.3451,44.5312,223.654}});
        addLine({{17.3451,44.5312,223.654},{17.3451,69.0475,237.87}});
        addLine({{17.3451,69.0475,237.87},{0,69.0475,237.87}});
        addLine({{68.9468,116.821,-100},{78.1084,100,-100}});
        addLine({{78.1084,100,-100},{83.6008,105.502,-130.47}});
        addLine({{83.6008,105.502,-130.47},{72.4264,126.019,-130.47}});
        addLine({{72.4264,126.019,-130.47},{68.9468,116.821,-100}});
        addLine({{37.27,116.821,-100},{68.9468,116.821,-100}});
        addLine({{68.9468,116.821,-100},{72.4264,126.019,-130.47}});
        addLine({{72.4264,126.019,-130.47},{33.7904,126.019,-130.47}});
        addLine({{33.7904,126.019,-130.47},{37.27,116.821,-100}});
        addLine({{28.1084,100,-100},{37.27,116.821,-100}});
        addLine({{37.27,116.821,-100},{33.7904,126.019,-130.47}});
        addLine({{33.7904,126.019,-130.47},{22.6161,105.502,-130.47}});
        addLine({{22.6161,105.502,-130.47},{28.1084,100,-100}});
        addLine({{28.1084,50,-100},{28.1084,100,-100}});
        addLine({{28.1084,100,-100},{22.6161,105.502,-130.47}});
        addLine({{22.6161,105.502,-130.47},{22.6161,44.5174,-130.47}});
        addLine({{22.6161,44.5174,-130.47},{28.1084,50,-100}});
        addLine({{78.1084,100,-100},{78.1084,50,-100}});
        addLine({{78.1084,50,-100},{83.6008,44.5174,-130.47}});
        addLine({{83.6008,44.5174,-130.47},{83.6008,105.502,-130.47}});
        addLine({{83.6008,105.502,-130.47},{78.1084,100,-100}});
        addLine({{83.6008,44.5174,-130.47},{73.6582,23.7831,-130.47}});
        addLine({{73.6582,23.7831,-130.47},{65.4973,44.1051,-92.3826}});
        addLine({{65.4973,44.1051,-92.3826},{71.4914,56.6052,-92.3826}});
        addLine({{71.4914,56.6052,-92.3826},{83.6008,44.5174,-130.47}});
        addLine({{32.5586,23.7831,-130.47},{22.6161,44.5174,-130.47}});
        addLine({{22.6161,44.5174,-130.47},{34.7254,56.6052,-92.3826}});
        addLine({{34.7254,56.6052,-92.3826},{40.7195,44.1051,-92.3826}});
        addLine({{40.7195,44.1051,-92.3826},{32.5586,23.7831,-130.47}});
        addLine({{73.6582,23.7831,-130.47},{32.5586,23.7831,-130.47}});
        addLine({{32.5586,23.7831,-130.47},{40.7195,44.1051,-92.3826}});
        addLine({{40.7195,44.1051,-92.3826},{65.4973,44.1051,-92.3826}});
        addLine({{65.4973,44.1051,-92.3826},{73.6582,23.7831,-130.47}});
        addLine({{72.4264,126.019,-130.47},{83.6008,105.502,-130.47}});
        addLine({{83.6008,105.502,-130.47},{71.4914,93.3712,-92.3826}});
        addLine({{71.4914,93.3712,-92.3826},{64.7547,105.74,-92.3826}});
        addLine({{64.7547,105.74,-92.3826},{72.4264,126.019,-130.47}});
        addLine({{33.7904,126.019,-130.47},{72.4264,126.019,-130.47}});
        addLine({{72.4264,126.019,-130.47},{64.7547,105.74,-92.3826}});
        addLine({{64.7547,105.74,-92.3826},{41.4621,105.74,-92.3826}});
        addLine({{41.4621,105.74,-92.3826},{33.7904,126.019,-130.47}});
        addLine({{22.6161,105.502,-130.47},{33.7904,126.019,-130.47}});
        addLine({{33.7904,126.019,-130.47},{41.4621,105.74,-92.3826}});
        addLine({{41.4621,105.74,-92.3826},{34.7254,93.3712,-92.3826}});
        addLine({{34.7254,93.3712,-92.3826},{22.6161,105.502,-130.47}});
        addLine({{83.6008,105.502,-130.47},{83.6008,44.5174,-130.47}});
        addLine({{83.6008,44.5174,-130.47},{71.4914,56.6052,-92.3826}});
        addLine({{71.4914,56.6052,-92.3826},{71.4914,93.3712,-92.3826}});
        addLine({{71.4914,93.3712,-92.3826},{83.6008,105.502,-130.47}});
        addLine({{22.6161,44.5174,-130.47},{22.6161,105.502,-130.47}});
        addLine({{22.6161,105.502,-130.47},{34.7254,93.3712,-92.3826}});
        addLine({{34.7254,93.3712,-92.3826},{34.7254,56.6052,-92.3826}});
        addLine({{34.7254,56.6052,-92.3826},{22.6161,44.5174,-130.47}});
        addLine({{34.7254,93.3712,-92.3826},{41.4621,105.74,-92.3826}});
        addLine({{41.4621,105.74,-92.3826},{64.7547,105.74,-92.3826}});
        addLine({{64.7547,105.74,-92.3826},{71.4914,93.3712,-92.3826}});
        addLine({{71.4914,93.3712,-92.3826},{71.4914,56.6052,-92.3826}});
        addLine({{71.4914,56.6052,-92.3826},{65.4973,44.1051,-92.3826}});
        addLine({{65.4973,44.1051,-92.3826},{40.7195,44.1051,-92.3826}});
        addLine({{40.7195,44.1051,-92.3826},{34.7254,56.6052,-92.3826}});
        addLine({{34.7254,56.6052,-92.3826},{34.7254,93.3712,-92.3826}});
        addLine({{159.759,36.7528,16.3479},{159.759,32.9895,-29.8727}});
        addLine({{159.759,32.9895,-29.8727},{241.411,21.3953,-59.7455}});
        addLine({{241.411,21.3953,-59.7455},{241.411,23.5056,-27.2798}});
        addLine({{241.411,23.5056,-27.2798},{159.759,36.7528,16.3479}});
        addLine({{159.759,32.9895,-29.8727},{127.571,36.7528,-133.18}});
        addLine({{127.571,36.7528,-133.18},{241.411,23.5056,-113.877}});
        addLine({{241.411,23.5056,-113.877},{241.411,21.3953,-59.7455}});
        addLine({{241.411,21.3953,-59.7455},{159.759,32.9895,-29.8727}});
        addLine({{159.759,41.9568,-29.8727},{159.759,36.7528,16.3479}});
        addLine({{159.759,36.7528,16.3479},{241.411,23.5056,-27.2798}});
        addLine({{241.411,23.5056,-27.2798},{241.411,26.4237,-59.7455}});
        addLine({{241.411,26.4237,-59.7455},{159.759,41.9568,-29.8727}});
        addLine({{127.571,36.7528,-133.18},{159.759,41.9568,-29.8727}});
        addLine({{159.759,41.9568,-29.8727},{241.411,26.4237,-59.7455}});
        addLine({{241.411,26.4237,-59.7455},{241.411,23.5056,-113.877}});
        addLine({{241.411,23.5056,-113.877},{127.571,36.7528,-133.18}});
        addLine({{241.411,21.3953,-59.7455},{241.411,23.5056,-113.877}});
        addLine({{241.411,23.5056,-113.877},{241.411,26.4237,-59.7455}});
        addLine({{241.411,26.4237,-59.7455},{241.411,23.5056,-27.2798}});
        addLine({{241.411,23.5056,-27.2798},{241.411,21.3953,-59.7455}});
        addLine({{78.1084,100,0},{78.1084,100,-100}});
        addLine({{78.1084,100,-100},{74.6796,106.296,-91.9498}});
        addLine({{74.6796,106.296,-91.9498},{73.5276,106.933,-20.6404}});
        addLine({{73.5276,106.933,-20.6404},{78.1084,100,0}});
        addLine({{74.6796,106.296,-91.9498},{72.3757,110.526,-91.9498}});
        addLine({{72.3757,110.526,-91.9498},{155.666,156.355,-149.38}});
        addLine({{155.666,156.355,-149.38},{156.882,154.122,-149.38}});
        addLine({{156.882,154.122,-149.38},{74.6796,106.296,-91.9498}});
        addLine({{73.5276,106.933,-20.6404},{74.6796,106.296,-91.9498}});
        addLine({{74.6796,106.296,-91.9498},{156.882,154.122,-149.38}});
        addLine({{156.882,154.122,-149.38},{156.882,154.122,-105.706}});
        addLine({{156.882,154.122,-105.706},{73.5276,106.933,-20.6404}});
        addLine({{68.9468,116.821,-13.4321},{78.1084,100,0}});
        addLine({{78.1084,100,0},{73.5276,106.933,-20.6404}});
        addLine({{73.5276,106.933,-20.6404},{68.9468,116.821,-13.4321}});
        addLine({{68.9468,116.821,-100},{68.9468,116.821,-13.4321}});
        addLine({{68.9468,116.821,-13.4321},{73.5276,106.933,-20.6404}});
        addLine({{73.5276,106.933,-20.6404},{72.3757,110.526,-91.9498}});
        addLine({{72.3757,110.526,-91.9498},{68.9468,116.821,-100}});
        addLine({{78.1084,50,59.9756},{78.1084,44.5836,0}});
        addLine({{78.1084,44.5836,0},{159.759,32.9895,-29.8727}});
        addLine({{159.759,32.9895,-29.8727},{159.759,36.7528,16.3479}});
        addLine({{159.759,36.7528,16.3479},{78.1084,50,59.9756}});
        addLine({{78.1084,44.5836,0},{78.1084,50,-100}});
        addLine({{78.1084,50,-100},{127.571,36.7528,-133.18}});
        addLine({{127.571,36.7528,-133.18},{159.759,32.9895,-29.8727}});
        addLine({{159.759,32.9895,-29.8727},{78.1084,44.5836,0}});
        addLine({{78.1084,57.4898,0},{78.1084,50,59.9756}});
        addLine({{78.1084,50,59.9756},{159.759,36.7528,16.3479}});
        addLine({{159.759,36.7528,16.3479},{159.759,41.9568,-29.8727}});
        addLine({{159.759,41.9568,-29.8727},{78.1084,57.4898,0}});
        addLine({{78.1084,50,-100},{78.1084,57.4898,0}});
        addLine({{78.1084,57.4898,0},{159.759,41.9568,-29.8727}});
        addLine({{159.759,41.9568,-29.8727},{127.571,36.7528,-133.18}});
        addLine({{127.571,36.7528,-133.18},{78.1084,50,-100}});
        addLine({{36.9608,91.1476,92.9138},{36.9608,58.8524,92.9138}});
        addLine({{36.9608,58.8524,92.9138},{36.9608,58.8524,73.9688}});
        addLine({{36.9608,58.8524,73.9688},{36.9608,91.1476,73.9688}});
        addLine({{36.9608,91.1476,73.9688},{36.9608,91.1476,92.9138}});
        addLine({{28.1084,50,100},{78.1084,50,59.9756}});
        addLine({{78.1084,50,59.9756},{69.2561,58.8524,67.0618}});
        addLine({{69.2561,58.8524,67.0618},{36.9608,58.8524,92.9138}});
        addLine({{36.9608,58.8524,92.9138},{28.1084,50,100}});
        addLine({{78.1084,50,59.9756},{78.1084,100,59.9756}});
        addLine({{78.1084,100,59.9756},{69.2561,91.1476,67.0618}});
        addLine({{69.2561,91.1476,67.0618},{69.2561,58.8524,67.0618}});
        addLine({{69.2561,58.8524,67.0618},{78.1084,50,59.9756}});
        addLine({{78.1084,100,59.9756},{28.1084,100,100}});
        addLine({{28.1084,100,100},{36.9608,91.1476,92.9138}});
        addLine({{36.9608,91.1476,92.9138},{69.2561,91.1476,67.0618}});
        addLine({{69.2561,91.1476,67.0618},{78.1084,100,59.9756}});
        addLine({{36.9608,58.8524,92.9138},{69.2561,58.8524,67.0618}});
        addLine({{69.2561,58.8524,67.0618},{69.2561,58.8524,48.1168}});
        addLine({{69.2561,58.8524,48.1168},{36.9608,58.8524,73.9688}});
        addLine({{36.9608,58.8524,73.9688},{36.9608,58.8524,92.9138}});
        addLine({{69.2561,58.8524,67.0618},{69.2561,91.1476,67.0618}});
        addLine({{69.2561,91.1476,67.0618},{69.2561,91.1476,48.1168}});
        addLine({{69.2561,91.1476,48.1168},{69.2561,58.8524,48.1168}});
        addLine({{69.2561,58.8524,48.1168},{69.2561,58.8524,67.0618}});
        addLine({{69.2561,91.1476,67.0618},{36.9608,91.1476,92.9138}});
        addLine({{36.9608,91.1476,92.9138},{36.9608,91.1476,73.9688}});
        addLine({{36.9608,91.1476,73.9688},{69.2561,91.1476,48.1168}});
        addLine({{69.2561,91.1476,48.1168},{69.2561,91.1476,67.0618}});
        addLine({{69.2561,91.1476,48.1168},{36.9608,91.1476,73.9688}});
        addLine({{36.9608,91.1476,73.9688},{36.9608,58.8524,73.9688}});
        addLine({{36.9608,58.8524,73.9688},{69.2561,58.8524,48.1168}});
        addLine({{69.2561,58.8524,48.1168},{69.2561,91.1476,48.1168}});
        addLine({{72.3757,110.526,-91.9498},{73.5276,106.933,-20.6404}});
        addLine({{73.5276,106.933,-20.6404},{156.882,154.122,-105.706}});
        addLine({{156.882,154.122,-105.706},{155.666,156.355,-149.38}});
        addLine({{155.666,156.355,-149.38},{72.3757,110.526,-91.9498}});
        addLine({{156.882,154.122,-149.38},{155.666,156.355,-149.38}});
        addLine({{155.666,156.355,-149.38},{156.882,154.122,-105.706}});
        addLine({{156.882,154.122,-105.706},{156.882,154.122,-149.38}});
        addLine({{-78.1084,100,-100},{-74.6796,106.296,-91.9498}});
        addLine({{-74.6796,106.296,-91.9498},{-72.3757,110.526,-91.9498}});
        addLine({{-72.3757,110.526,-91.9498},{-68.9468,116.821,-100}});
        addLine({{-68.9468,116.821,-100},{-78.1084,100,-100}});
        addLine({{-69.9568,33.0004,-100},{-73.6582,23.7831,-130.47}});
        addLine({{-73.6582,23.7831,-130.47},{-32.5586,23.7831,-130.47}});
        addLine({{-32.5586,23.7831,-130.47},{-36.2601,33.0004,-100}});
        addLine({{-36.2601,33.0004,-100},{-69.9568,33.0004,-100}});
        addLine({{-78.1084,100,0},{-78.1084,57.4898,0}});
        addLine({{-78.1084,57.4898,0},{-78.1084,50,59.9756}});
        addLine({{-78.1084,50,59.9756},{-78.1084,100,59.9756}});
        addLine({{-78.1084,100,59.9756},{-78.1084,100,0}});
        addLine({{-28.1084,44.5836,0},{0,44.5836,0}});
        addLine({{0,44.5836,0},{0,50,100}});
        addLine({{0,50,100},{-28.1084,50,100}});
        addLine({{-28.1084,50,100},{-28.1084,44.5836,0}});
        addLine({{-17.3622,140,100},{-17.3622,99.9438,193.064}});
        addLine({{-17.3622,99.9438,193.064},{0,99.9438,193.064}});
        addLine({{0,99.9438,193.064},{0,140,100}});
        addLine({{0,140,100},{-17.3622,140,100}});
        addLine({{-17.3622,140,100},{0,140,100}});
        addLine({{0,140,100},{0,117.966,0}});
        addLine({{0,117.966,0},{-28.1084,117.966,0}});
        addLine({{-28.1084,117.966,0},{-17.3622,140,100}});
        addLine({{-78.1084,100,-100},{-78.1084,50,-100}});
        addLine({{-78.1084,50,-100},{-78.1084,57.4898,0}});
        addLine({{-78.1084,57.4898,0},{-78.1084,100,0}});
        addLine({{-78.1084,100,0},{-78.1084,100,-100}});
        addLine({{-28.1084,50,-100},{0,50,-100}});
        addLine({{0,50,-100},{0,44.5836,0}});
        addLine({{0,44.5836,0},{-28.1084,44.5836,0}});
        addLine({{-28.1084,44.5836,0},{-28.1084,50,-100}});
        addLine({{-28.1084,100,-100},{-37.27,116.821,-100}});
        addLine({{-37.27,116.821,-100},{-37.27,116.821,-13.4321}});
        addLine({{-37.27,116.821,-13.4321},{-28.1084,100,0}});
        addLine({{-28.1084,100,0},{-28.1084,100,-100}});
        addLine({{0,100,-100},{0,50,-100}});
        addLine({{0,50,-100},{-28.1084,50,-100}});
        addLine({{-28.1084,50,-100},{-28.1084,100,-100}});
        addLine({{-28.1084,100,-100},{0,100,-100}});
        addLine({{-78.1084,44.5836,0},{-28.1084,44.5836,0}});
        addLine({{-28.1084,44.5836,0},{-28.1084,50,100}});
        addLine({{-28.1084,50,100},{-78.1084,50,59.9756}});
        addLine({{-78.1084,50,59.9756},{-78.1084,44.5836,0}});
        addLine({{-28.1084,100,100},{-36.9608,91.1476,92.9138}});
        addLine({{-36.9608,91.1476,92.9138},{-36.9608,58.8524,92.9138}});
        addLine({{-36.9608,58.8524,92.9138},{-28.1084,50,100}});
        addLine({{-28.1084,50,100},{-28.1084,100,100}});
        addLine({{-78.1084,100,59.9756},{-28.1084,100,100}});
        addLine({{-28.1084,100,100},{-28.1084,100,0}});
        addLine({{-28.1084,100,0},{-78.1084,100,0}});
        addLine({{-78.1084,100,0},{-78.1084,100,59.9756}});
        addLine({{-28.1084,44.5836,0},{-36.2601,33.0004,-13.4321}});
        addLine({{-36.2601,33.0004,-13.4321},{-36.2601,33.0004,-100}});
        addLine({{-36.2601,33.0004,-100},{-28.1084,50,-100}});
        addLine({{-28.1084,50,-100},{-28.1084,44.5836,0}});
        addLine({{-28.1084,100,100},{-28.1084,76.3507,179.383}});
        addLine({{-28.1084,76.3507,179.383},{-17.3622,99.9438,193.064}});
        addLine({{-17.3622,99.9438,193.064},{-17.3622,140,100}});
        addLine({{-17.3622,140,100},{-28.1084,100,100}});
        addLine({{-17.3622,140,100},{-28.1084,117.966,0}});
        addLine({{-28.1084,117.966,0},{-28.1084,100,0}});
        addLine({{-28.1084,100,0},{-28.1084,100,100}});
        addLine({{-28.1084,100,100},{-17.3622,140,100}});
        addLine({{-28.1084,50,100},{-28.1084,46.8594,162.282}});
        addLine({{-28.1084,46.8594,162.282},{-28.1084,76.3507,179.383}});
        addLine({{-28.1084,76.3507,179.383},{-28.1084,100,100}});
        addLine({{-28.1084,100,100},{-28.1084,50,100}});
        addLine({{0,50,100},{0,46.8594,162.282}});
        addLine({{0,46.8594,162.282},{-28.1084,46.8594,162.282}});
        addLine({{-28.1084,46.8594,162.282},{-28.1084,50,100}});
        addLine({{-28.1084,50,100},{0,50,100}});
        addLine({{0,46.8594,162.282},{0,44.5312,223.654}});
        addLine({{0,44.5312,223.654},{-17.3451,44.5312,223.654}});
        addLine({{-17.3451,44.5312,223.654},{-28.1084,46.8594,162.282}});
        addLine({{-28.1084,46.8594,162.282},{0,46.8594,162.282}});
        addLine({{-28.1084,46.8594,162.282},{-17.3451,44.5312,223.654}});
        addLine({{-17.3451,44.5312,223.654},{-17.3451,69.0475,237.87}});
        addLine({{-17.3451,69.0475,237.87},{-28.1084,76.3507,179.383}});
        addLine({{-28.1084,76.3507,179.383},{-28.1084,46.8594,162.282}});
        addLine({{-28.1084,100,-100},{-28.1084,117.966,0}});
        addLine({{-28.1084,117.966,0},{0,117.966,0}});
        addLine({{0,117.966,0},{0,100,-100}});
        addLine({{0,100,-100},{-28.1084,100,-100}});
        addLine({{-28.1084,100,0},{-28.1084,117.966,0}});
        addLine({{-28.1084,117.966,0},{-28.1084,100,-100}});
        addLine({{-28.1084,100,-100},{-28.1084,100,0}});
        addLine({{-28.1084,100,0},{-37.27,116.821,-13.4321}});
        addLine({{-37.27,116.821,-13.4321},{-68.9468,116.821,-13.4321}});
        addLine({{-68.9468,116.821,-13.4321},{-78.1084,100,0}});
        addLine({{-78.1084,100,0},{-28.1084,100,0}});
        addLine({{-68.9468,116.821,-13.4321},{-37.27,116.821,-13.4321}});
        addLine({{-37.27,116.821,-13.4321},{-37.27,116.821,-100}});
        addLine({{-37.27,116.821,-100},{-68.9468,116.821,-100}});
        addLine({{-68.9468,116.821,-100},{-68.9468,116.821,-13.4321}});
        addLine({{-36.2601,33.0004,-100},{-32.5586,23.7831,-130.47}});
        addLine({{-32.5586,23.7831,-130.47},{-22.6161,44.5174,-130.47}});
        addLine({{-22.6161,44.5174,-130.47},{-28.1084,50,-100}});
        addLine({{-28.1084,50,-100},{-36.2601,33.0004,-100}});
        addLine({{-69.9568,33.0004,-100},{-36.2601,33.0004,-100}});
        addLine({{-36.2601,33.0004,-100},{-36.2601,33.0004,-13.4321}});
        addLine({{-36.2601,33.0004,-13.4321},{-69.9568,33.0004,-13.4321}});
        addLine({{-69.9568,33.0004,-13.4321},{-69.9568,33.0004,-100}});
        addLine({{-78.1084,44.5836,0},{-69.9568,33.0004,-13.4321}});
        addLine({{-69.9568,33.0004,-13.4321},{-36.2601,33.0004,-13.4321}});
        addLine({{-36.2601,33.0004,-13.4321},{-28.1084,44.5836,0}});
        addLine({{-28.1084,44.5836,0},{-78.1084,44.5836,0}});
        addLine({{-78.1084,50,-100},{-83.6008,44.5174,-130.47}});
        addLine({{-83.6008,44.5174,-130.47},{-73.6582,23.7831,-130.47}});
        addLine({{-73.6582,23.7831,-130.47},{-69.9568,33.0004,-100}});
        addLine({{-69.9568,33.0004,-100},{-78.1084,50,-100}});
        addLine({{-78.1084,50,-100},{-69.9568,33.0004,-100}});
        addLine({{-69.9568,33.0004,-100},{-69.9568,33.0004,-13.4321}});
        addLine({{-69.9568,33.0004,-13.4321},{-78.1084,44.5836,0}});
        addLine({{-78.1084,44.5836,0},{-78.1084,50,-100}});
        addLine({{-28.1084,76.3507,179.383},{-17.3451,69.0475,237.87}});
        addLine({{-17.3451,69.0475,237.87},{-17.3622,99.9438,193.064}});
        addLine({{-17.3622,99.9438,193.064},{-28.1084,76.3507,179.383}});
        addLine({{-17.3622,99.9438,193.064},{-17.3451,69.0475,237.87}});
        addLine({{-17.3451,69.0475,237.87},{0,69.0475,237.87}});
        addLine({{0,69.0475,237.87},{0,99.9438,193.064}});
        addLine({{0,99.9438,193.064},{-17.3622,99.9438,193.064}});
        addLine({{0,69.0475,237.87},{-17.3451,69.0475,237.87}});
        addLine({{-17.3451,69.0475,237.87},{-17.3451,44.5312,223.654}});
        addLine({{-17.3451,44.5312,223.654},{0,44.5312,223.654}});
        addLine({{0,44.5312,223.654},{0,69.0475,237.87}});
        addLine({{-68.9468,116.821,-100},{-72.4264,126.019,-130.47}});
        addLine({{-72.4264,126.019,-130.47},{-83.6008,105.502,-130.47}});
        addLine({{-83.6008,105.502,-130.47},{-78.1084,100,-100}});
        addLine({{-78.1084,100,-100},{-68.9468,116.821,-100}});
        addLine({{-37.27,116.821,-100},{-33.7904,126.019,-130.47}});
        addLine({{-33.7904,126.019,-130.47},{-72.4264,126.019,-130.47}});
        addLine({{-72.4264,126.019,-130.47},{-68.9468,116.821,-100}});
        addLine({{-68.9468,116.821,-100},{-37.27,116.821,-100}});
        addLine({{-28.1084,100,-100},{-22.6161,105.502,-130.47}});
        addLine({{-22.6161,105.502,-130.47},{-33.7904,126.019,-130.47}});
        addLine({{-33.7904,126.019,-130.47},{-37.27,116.821,-100}});
        addLine({{-37.27,116.821,-100},{-28.1084,100,-100}});
        addLine({{-28.1084,50,-100},{-22.6161,44.5174,-130.47}});
        addLine({{-22.6161,44.5174,-130.47},{-22.6161,105.502,-130.47}});
        addLine({{-22.6161,105.502,-130.47},{-28.1084,100,-100}});
        addLine({{-28.1084,100,-100},{-28.1084,50,-100}});
        addLine({{-78.1084,100,-100},{-83.6008,105.502,-130.47}});
        addLine({{-83.6008,105.502,-130.47},{-83.6008,44.5174,-130.47}});
        addLine({{-83.6008,44.5174,-130.47},{-78.1084,50,-100}});
        addLine({{-78.1084,50,-100},{-78.1084,100,-100}});
        addLine({{-83.6008,44.5174,-130.47},{-71.4914,56.6052,-92.3826}});
        addLine({{-71.4914,56.6052,-92.3826},{-65.4973,44.1051,-92.3826}});
        addLine({{-65.4973,44.1051,-92.3826},{-73.6582,23.7831,-130.47}});
        addLine({{-73.6582,23.7831,-130.47},{-83.6008,44.5174,-130.47}});
        addLine({{-32.5586,23.7831,-130.47},{-40.7195,44.1051,-92.3826}});
        addLine({{-40.7195,44.1051,-92.3826},{-34.7254,56.6052,-92.3826}});
        addLine({{-34.7254,56.6052,-92.3826},{-22.6161,44.5174,-130.47}});
        addLine({{-22.6161,44.5174,-130.47},{-32.5586,23.7831,-130.47}});
        addLine({{-73.6582,23.7831,-130.47},{-65.4973,44.1051,-92.3826}});
        addLine({{-65.4973,44.1051,-92.3826},{-40.7195,44.1051,-92.3826}});
        addLine({{-40.7195,44.1051,-92.3826},{-32.5586,23.7831,-130.47}});
        addLine({{-32.5586,23.7831,-130.47},{-73.6582,23.7831,-130.47}});
        addLine({{-72.4264,126.019,-130.47},{-64.7547,105.74,-92.3826}});
        addLine({{-64.7547,105.74,-92.3826},{-71.4914,93.3712,-92.3826}});
        addLine({{-71.4914,93.3712,-92.3826},{-83.6008,105.502,-130.47}});
        addLine({{-83.6008,105.502,-130.47},{-72.4264,126.019,-130.47}});
        addLine({{-33.7904,126.019,-130.47},{-41.4621,105.74,-92.3826}});
        addLine({{-41.4621,105.74,-92.3826},{-64.7547,105.74,-92.3826}});
        addLine({{-64.7547,105.74,-92.3826},{-72.4264,126.019,-130.47}});
        addLine({{-72.4264,126.019,-130.47},{-33.7904,126.019,-130.47}});
        addLine({{-22.6161,105.502,-130.47},{-34.7254,93.3712,-92.3826}});
        addLine({{-34.7254,93.3712,-92.3826},{-41.4621,105.74,-92.3826}});
        addLine({{-41.4621,105.74,-92.3826},{-33.7904,126.019,-130.47}});
        addLine({{-33.7904,126.019,-130.47},{-22.6161,105.502,-130.47}});
        addLine({{-83.6008,105.502,-130.47},{-71.4914,93.3712,-92.3826}});
        addLine({{-71.4914,93.3712,-92.3826},{-71.4914,56.6052,-92.3826}});
        addLine({{-71.4914,56.6052,-92.3826},{-83.6008,44.5174,-130.47}});
        addLine({{-83.6008,44.5174,-130.47},{-83.6008,105.502,-130.47}});
        addLine({{-22.6161,44.5174,-130.47},{-34.7254,56.6052,-92.3826}});
        addLine({{-34.7254,56.6052,-92.3826},{-34.7254,93.3712,-92.3826}});
        addLine({{-34.7254,93.3712,-92.3826},{-22.6161,105.502,-130.47}});
        addLine({{-22.6161,105.502,-130.47},{-22.6161,44.5174,-130.47}});
        addLine({{-34.7254,93.3712,-92.3826},{-34.7254,56.6052,-92.3826}});
        addLine({{-34.7254,56.6052,-92.3826},{-40.7195,44.1051,-92.3826}});
        addLine({{-40.7195,44.1051,-92.3826},{-65.4973,44.1051,-92.3826}});
        addLine({{-65.4973,44.1051,-92.3826},{-71.4914,56.6052,-92.3826}});
        addLine({{-71.4914,56.6052,-92.3826},{-71.4914,93.3712,-92.3826}});
        addLine({{-71.4914,93.3712,-92.3826},{-64.7547,105.74,-92.3826}});
        addLine({{-64.7547,105.74,-92.3826},{-41.4621,105.74,-92.3826}});
        addLine({{-41.4621,105.74,-92.3826},{-34.7254,93.3712,-92.3826}});
        addLine({{-159.759,36.7528,16.3479},{-241.411,23.5056,-27.2798}});
        addLine({{-241.411,23.5056,-27.2798},{-241.411,21.3953,-59.7455}});
        addLine({{-241.411,21.3953,-59.7455},{-159.759,32.9895,-29.8727}});
        addLine({{-159.759,32.9895,-29.8727},{-159.759,36.7528,16.3479}});
        addLine({{-159.759,32.9895,-29.8727},{-241.411,21.3953,-59.7455}});
        addLine({{-241.411,21.3953,-59.7455},{-241.411,23.5056,-113.877}});
        addLine({{-241.411,23.5056,-113.877},{-127.571,36.7528,-133.18}});
        addLine({{-127.571,36.7528,-133.18},{-159.759,32.9895,-29.8727}});
        addLine({{-159.759,41.9568,-29.8727},{-241.411,26.4237,-59.7455}});
        addLine({{-241.411,26.4237,-59.7455},{-241.411,23.5056,-27.2798}});
        addLine({{-241.411,23.5056,-27.2798},{-159.759,36.7528,16.3479}});
        addLine({{-159.759,36.7528,16.3479},{-159.759,41.9568,-29.8727}});
        addLine({{-127.571,36.7528,-133.18},{-241.411,23.5056,-113.877}});
        addLine({{-241.411,23.5056,-113.877},{-241.411,26.4237,-59.7455}});
        addLine({{-241.411,26.4237,-59.7455},{-159.759,41.9568,-29.8727}});
        addLine({{-159.759,41.9568,-29.8727},{-127.571,36.7528,-133.18}});
        addLine({{-241.411,21.3953,-59.7455},{-241.411,23.5056,-27.2798}});
        addLine({{-241.411,23.5056,-27.2798},{-241.411,26.4237,-59.7455}});
        addLine({{-241.411,26.4237,-59.7455},{-241.411,23.5056,-113.877}});
        addLine({{-241.411,23.5056,-113.877},{-241.411,21.3953,-59.7455}});
        addLine({{-78.1084,100,0},{-73.5276,106.933,-20.6404}});
        addLine({{-73.5276,106.933,-20.6404},{-74.6796,106.296,-91.9498}});
        addLine({{-74.6796,106.296,-91.9498},{-78.1084,100,-100}});
        addLine({{-78.1084,100,-100},{-78.1084,100,0}});
        addLine({{-74.6796,106.296,-91.9498},{-156.882,154.122,-149.38}});
        addLine({{-156.882,154.122,-149.38},{-155.666,156.355,-149.38}});
        addLine({{-155.666,156.355,-149.38},{-72.3757,110.526,-91.9498}});
        addLine({{-72.3757,110.526,-91.9498},{-74.6796,106.296,-91.9498}});
        addLine({{-73.5276,106.933,-20.6404},{-156.882,154.122,-105.706}});
        addLine({{-156.882,154.122,-105.706},{-156.882,154.122,-149.38}});
        addLine({{-156.882,154.122,-149.38},{-74.6796,106.296,-91.9498}});
        addLine({{-74.6796,106.296,-91.9498},{-73.5276,106.933,-20.6404}});
        addLine({{-68.9468,116.821,-13.4321},{-73.5276,106.933,-20.6404}});
        addLine({{-73.5276,106.933,-20.6404},{-78.1084,100,0}});
        addLine({{-78.1084,100,0},{-68.9468,116.821,-13.4321}});
        addLine({{-68.9468,116.821,-100},{-72.3757,110.526,-91.9498}});
        addLine({{-72.3757,110.526,-91.9498},{-73.5276,106.933,-20.6404}});
        addLine({{-73.5276,106.933,-20.6404},{-68.9468,116.821,-13.4321}});
        addLine({{-68.9468,116.821,-13.4321},{-68.9468,116.821,-100}});
        addLine({{-78.1084,50,59.9756},{-159.759,36.7528,16.3479}});
        addLine({{-159.759,36.7528,16.3479},{-159.759,32.9895,-29.8727}});
        addLine({{-159.759,32.9895,-29.8727},{-78.1084,44.5836,0}});
        addLine({{-78.1084,44.5836,0},{-78.1084,50,59.9756}});
        addLine({{-78.1084,44.5836,0},{-159.759,32.9895,-29.8727}});
        addLine({{-159.759,32.9895,-29.8727},{-127.571,36.7528,-133.18}});
        addLine({{-127.571,36.7528,-133.18},{-78.1084,50,-100}});
        addLine({{-78.1084,50,-100},{-78.1084,44.5836,0}});
        addLine({{-78.1084,57.4898,0},{-159.759,41.9568,-29.8727}});
        addLine({{-159.759,41.9568,-29.8727},{-159.759,36.7528,16.3479}});
        addLine({{-159.759,36.7528,16.3479},{-78.1084,50,59.9756}});
        addLine({{-78.1084,50,59.9756},{-78.1084,57.4898,0}});
        addLine({{-78.1084,50,-100},{-127.571,36.7528,-133.18}});
        addLine({{-127.571,36.7528,-133.18},{-159.759,41.9568,-29.8727}});
        addLine({{-159.759,41.9568,-29.8727},{-78.1084,57.4898,0}});
        addLine({{-78.1084,57.4898,0},{-78.1084,50,-100}});
        addLine({{-36.9608,91.1476,92.9138},{-36.9608,91.1476,73.9688}});
        addLine({{-36.9608,91.1476,73.9688},{-36.9608,58.8524,73.9688}});
        addLine({{-36.9608,58.8524,73.9688},{-36.9608,58.8524,92.9138}});
        addLine({{-36.9608,58.8524,92.9138},{-36.9608,91.1476,92.9138}});
        addLine({{-28.1084,50,100},{-36.9608,58.8524,92.9138}});
        addLine({{-36.9608,58.8524,92.9138},{-69.2561,58.8524,67.0618}});
        addLine({{-69.2561,58.8524,67.0618},{-78.1084,50,59.9756}});
        addLine({{-78.1084,50,59.9756},{-28.1084,50,100}});
        addLine({{-78.1084,50,59.9756},{-69.2561,58.8524,67.0618}});
        addLine({{-69.2561,58.8524,67.0618},{-69.2561,91.1476,67.0618}});
        addLine({{-69.2561,91.1476,67.0618},{-78.1084,100,59.9756}});
        addLine({{-78.1084,100,59.9756},{-78.1084,50,59.9756}});
        addLine({{-78.1084,100,59.9756},{-69.2561,91.1476,67.0618}});
        addLine({{-69.2561,91.1476,67.0618},{-36.9608,91.1476,92.9138}});
        addLine({{-36.9608,91.1476,92.9138},{-28.1084,100,100}});
        addLine({{-28.1084,100,100},{-78.1084,100,59.9756}});
        addLine({{-36.9608,58.8524,92.9138},{-36.9608,58.8524,73.9688}});
        addLine({{-36.9608,58.8524,73.9688},{-69.2561,58.8524,48.1168}});
        addLine({{-69.2561,58.8524,48.1168},{-69.2561,58.8524,67.0618}});
        addLine({{-69.2561,58.8524,67.0618},{-36.9608,58.8524,92.9138}});
        addLine({{-69.2561,58.8524,67.0618},{-69.2561,58.8524,48.1168}});
        addLine({{-69.2561,58.8524,48.1168},{-69.2561,91.1476,48.1168}});
        addLine({{-69.2561,91.1476,48.1168},{-69.2561,91.1476,67.0618}});
        addLine({{-69.2561,91.1476,67.0618},{-69.2561,58.8524,67.0618}});
        addLine({{-69.2561,91.1476,67.0618},{-69.2561,91.1476,48.1168}});
        addLine({{-69.2561,91.1476,48.1168},{-36.9608,91.1476,73.9688}});
        addLine({{-36.9608,91.1476,73.9688},{-36.9608,91.1476,92.9138}});
        addLine({{-36.9608,91.1476,92.9138},{-69.2561,91.1476,67.0618}});
        addLine({{-69.2561,91.1476,48.1168},{-69.2561,58.8524,48.1168}});
        addLine({{-69.2561,58.8524,48.1168},{-36.9608,58.8524,73.9688}});
        addLine({{-36.9608,58.8524,73.9688},{-36.9608,91.1476,73.9688}});
        addLine({{-36.9608,91.1476,73.9688},{-69.2561,91.1476,48.1168}});
        addLine({{-72.3757,110.526,-91.9498},{-155.666,156.355,-149.38}});
        addLine({{-155.666,156.355,-149.38},{-156.882,154.122,-105.706}});
        addLine({{-156.882,154.122,-105.706},{-73.5276,106.933,-20.6404}});
        addLine({{-73.5276,106.933,-20.6404},{-72.3757,110.526,-91.9498}});
        addLine({{-156.882,154.122,-149.38},{-156.882,154.122,-105.706}});
        addLine({{-156.882,154.122,-105.706},{-155.666,156.355,-149.38}});
        addLine({{-155.666,156.355,-149.38},{-156.882,154.122,-149.38}});

    }
}