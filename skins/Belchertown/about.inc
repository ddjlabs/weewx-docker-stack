#encoding UTF-8
#set $have_voltage = 0
#for $x in [$day.consBatteryVoltage, $day.heatingVoltage, $day.supplyVoltage, $day.referenceVoltage]
  #if $x.has_data
    #set $have_voltage = 1
  #end if
#end for
<script type='text/javascript'>showChart("about");</script>
<div class="entry-content about-outer" itemprop="text">
   <div class="row" style="margin-top:15px;">
     <div class="col-sm-4" style="margin-right:10px;">
       <img src="../images/largoweather_acurite_station.jpg" />
       <br>
       <div id="rxchart" style="margin-top:30px;"></div>
       <div id="rxchartyear" style="margin-top:30px;"></div>
       <br>
       <img src="../images/largoweather_station_setup.jpg" />
     </div>
     <div class=col-sm-8" style="padding-top:10px;">
	<h2>About LargoWeather.com</h2>
	<p>I created LargoWeather.com as an evolving project to learn and understand Python3, Docker Containers, and MariaDB. My family gave me a Acurite 6307 weather station 3 years ago and I thought it would be wonderful to check on the local conditions via the web.</p>
        <p>This weather station runs on a Raspberry Pi 4 connected directly to the Acurite 6307 Console</p>
        <ul>
          <li>Station hardware: $station.hardware</li>
          <li>Server uptime: $station.os_uptime</li>
          <li>WeeWX uptime: $station.uptime</li>
          <li>WeeWX version: $station.version</li>
          <li>Belchertown Skin Version: $belchertown_version</li>

          #if $day.rxCheckPercent.has_data
            <li>Signal Quality: $current.rxCheckPercent</li>
          #end if
          #if $day.txBatteryStatus.has_data
            <li>Transmitter Battery:
            #if $current.txBatteryStatus.raw == 0
              <span style="color:#44aa44;">OK</span>
            #else
              <span style="color:#aa4444;">LOW</span>
            #end if
          #end if
          </li>
        </ul>
        </p>
        <h3>Software used:</h3>
        <p>
          <ul>
                <li><a href="http://www.weewx.com/" target="_blank">weewx</a> weather station software</li>
                <li><a href="http://www.highcharts.com/" target="_blank">HighCharts</a> for the various charts on the website</li>
                <li>The <a href="https://github.com/poblabs/weewx-belchertown" target="_blank">Belchertown skin</a> theme built for weewx</li>
                <li><a href="https://obrienlabs.net/go/mqttbroker" target="_blank">MQTT as the broker</a> for instant data transfer from weather station to website</li>
          </ul>
        </p>
        <h3>Credits:</h3>
        <p>
            <ul>
                <li>Thanks to Pat Obrien at <a href="https://belchertownweather.com" target="_blank">BelchertownWeather.com</a> for this amazing website for weewx!</li>
                <li>Forecast data <a href="https://www.aerisweather.com/account/member/" target="_blank">Powered by AERIS Weather</a></li>
                <li>Earthquake data from <a href="http://earthquake.usgs.gov/fdsnws/event/1/" target="_blank">USGS.gov Earthquake Catalog Developer API</a></li>
            </ul>
        </p>
     </div>
     <div class="clear"></div>
   </div>
</div>
