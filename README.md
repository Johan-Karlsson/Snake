# Welcome to my C++ implementation of "Snake"
Unfortunately, I have been to lazy to add a menu and score count to the game, but the basics are all there. The game is built using a library called ncurses
which can be downloaded and installed fairly simple, but I highly suggest that you run the game as a docker container.
## Run the game in docker
1. Clone the repo and open a terminal within it
2. Build the image using `docker build --rm -t snake .`
3. Run the image using `docker run --rm -it snake:latest`
