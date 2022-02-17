FROM mitct02/weewx:4.5.1

WORKDIR /home/weewx

ADD config/weewx.conf /home/weewx/
ADD extensions/*.zip /home/weewx/extensions/
ADD bin/run /etc/service/weewx/
RUN chmod 755 /etc/service/weewx/run

RUN ./bin/wee_extension --config=weewx.conf --install /home/weewx/extensions/weewx-mqtt.zip
RUN ./bin/wee_extension --config=weewx.conf --install /home/weewx/extensions/weewx-belchertown-master.zip
RUN ./bin/wee_extension --config=weewx.conf --install /home/weewx/extensions/weewx-windy.zip

