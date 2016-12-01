FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
ARG http_proxy
ARG https_proxy
RUN apt-get update && apt-get install -y net-tools tcpdump openssh-client vim haproxy
COPY start_haproxy.sh /
RUN chmod a+rx /start_haproxy.sh
COPY config /config/
ENTRYPOINT ["/start_haproxy.sh"]
CMD []