FROM ubuntu
MAINTAINER Marc Despland <marc.despland@orange.com>
RUN apt-get update && apt-get install -y apache2 curl net-tools tcpdump openssh-client vim
RUN mkdir -p /var/run/apache2; mkdir -p /var/lock/apache2
WORKDIR /var/www/html
EXPOSE 666
CMD . /etc/apache2/envvars; /usr/sbin/apache2 -DFOREGROUND
COPY apache2.conf	/etc/apache2/
COPY envvars	/etc/apache2/
COPY ports.conf	/etc/apache2/
COPY 000-default.conf /etc/apache2/sites-available/
RUN ln -s /etc/apache2/mods-available/proxy.load /etc/apache2/mods-enabled/
RUN ln -s /etc/apache2/mods-available/proxy.conf /etc/apache2/mods-enabled/
RUN ln -s /etc/apache2/mods-available/proxy_http.load /etc/apache2/mods-enabled/
RUN ln -s /etc/apache2/mods-available/rewrite.load /etc/apache2/mods-enabled/