FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
RUN apt-get update && apt-get install -y g++ build-essential net-tools tcpdump openssh-client git
RUN mkdir /project ; cd /project; git clone https://github.com/marc-despland/tcp_timewait.git
WORKDIR /project/tcp_timewait
RUN make timewait_client
ENTRYPOINT ["./timewait_client", "-c", "666", ,"-f", "667", "-t", "server", "-s"]
CMD []