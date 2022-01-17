FROM gcc:4.9

RUN apt-get update
RUN apt-get -y install libncurses5-dev
RUN apt-get -y install build-essential

COPY . .

RUN make clean
RUN make

CMD ["make", "run"]