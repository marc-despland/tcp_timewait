#!/bin/bash

option='kal'
if [ "$1" = 'tun' ] ; then
	option='tun';
fi
if [ "$1" = 'pcl' ] ; then
	option='pcl';
fi
if [ "$1" = 'scl' ] ; then
	option='scl';
fi
if [ "$1" = 'fcl' ] ; then
	option='fcl';
fi
if [ "$1" = 'pcl2' ] ; then
	option='pcl2';
fi
if [ "$1" = 'scl2' ] ; then
	option='scl2';
fi
cp /config/haproxy_$option.cfg /etc/haproxy/haproxy.cfg
exec /usr/sbin/haproxy -f /etc/haproxy/haproxy.cfg -db