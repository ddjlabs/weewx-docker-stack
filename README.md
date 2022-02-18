# weewx-docker-stack
My Docker Compose stack and configuration for WeeWx.

These files build out my weewx configuration. I create a custom docker image based from Tom Mitchell's WeeWX docker image and install belchertown, windy, and MQTT. I then setup the following containers to run my WeeWX solution:

1. NGNIX web server
2. MQTT Broker to support MQTT messages for live updates from WeeWX itself and the web client
3. WeeWX Engine.
4. MariaDB Database engine to store the data.


The entire stack runs within its own docker network and is managed in the config files.

# Assumptions
1. Setup a weewx user account with sudo privileges on your target Linux Server.
2. Setup the following directories (You can replace /media/docker/volumes with something else):
   - /media/docker/volumes/mariadb
   - /media/docker/volumes/weewx/mosquitto/config
   - /media/docker/volumes/weewx/mosquitto/data
   - /media/docker/volumes/weewx/mosquitto/log
   - /media/docker/volumes/weewx/config
   - /media/docker/volumes/weewx/skins/Belchertown
   - /media/docker/volumes/weewx/html
3. Ensure your WeeWX user has read/write privileges to these directories
4. Ensure your docker service user has read/write privileges to these directories
5. Verify that your station is pulled in via USB or configure WeeWX to get the data from your station in other ways.
