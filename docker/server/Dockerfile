FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
RUN apt-get update && apt-get install -y g++ build-essential net-tools tcpdump openssh-client git curl
RUN mkdir /project ; cd /project; git clone https://github.com/marc-despland/tcp_timewait.git
WORKDIR /project/tcp_timewait
RUN make timewait_server
ENTRYPOINT ["./timewait_server", "-p", "666", "-s"]
CMD []