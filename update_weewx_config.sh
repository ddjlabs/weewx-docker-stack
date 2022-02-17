#!/usr/bin/env bash

WEEWX_VERSION=4.5.1

git pull
cd docker-build
sudo docker build -t weewx:$WEEWX_VERSION .

cd ..
echo copying key configuration files and skins to target docker volume directories
sudo cp docker-build/config/weewx.conf /media/docker/volumes/weewx/config/
sudo cp -r skins/* /media/docker/volumes/weewx/skins/
sudo cp mosquitto_mqtt/config/* /media/docker/volumes/weewx/mosquitto/config/
echo copy complete.

