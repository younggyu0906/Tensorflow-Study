package koreatech.cse.rest.client;

import koreatech.cse.rest.client.domain.Temperature;
import org.springframework.http.ResponseEntity;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.RestTemplate;

import java.net.URI;
import java.util.Date;
import java.util.List;

/**
 * Hello world!
 *
 */
public class App 
{
    public static final String REST_SERVICE_URI = "http://localhost:8080/thermometer";

    public static void main( String[] args ) {
        System.out.println( "Hello World!" );
        getTemperature();
        getTemperatureXml();
        getTemperatureByLocation();
        getTemperatureByLocationXml();
        createTemperature();
        updateTemperature();
        deleteTemperature();
    }

    private static void getTemperature() {
        System.out.println("Testing GET METHOD (1)----------");
        RestTemplate restTemplate = new RestTemplate();
        try {
            ResponseEntity<Temperature> temperatureResponseEntity = restTemplate.getForEntity(
                REST_SERVICE_URI + "/temperature/temp1", Temperature.class
            );
            Temperature temperature = temperatureResponseEntity.getBody();
            System.out.println(temperature);
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }

    private static void getTemperatureXml() {
        System.out.println("Testing GET METHOD (2)----------");
        RestTemplate restTemplate = new RestTemplate();
        try {
            ResponseEntity<Temperature> temperatureResponseEntity = restTemplate.getForEntity(
                    REST_SERVICE_URI + "/xml/temperature/temp1", Temperature.class
            );
            Temperature temperature = temperatureResponseEntity.getBody();
            System.out.println(temperature);
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }

    private static void getTemperatureByLocation() {
        System.out.println("Testing GET METHOD (3)----------");
        RestTemplate restTemplate = new RestTemplate();
        try {
            ResponseEntity<List> listResponseEntity = restTemplate.getForEntity(
                    REST_SERVICE_URI + "/temperature/location/KoreaTech", List.class
            );
            List<Temperature> temperatureList = listResponseEntity.getBody();
            for (int i = 0; i < temperatureList.size(); i++) {
                System.out.println(temperatureList.get(i));
            }
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }

    private static void getTemperatureByLocationXml() {
        System.out.println("Testing GET METHOD (4)----------");
        RestTemplate restTemplate = new RestTemplate();
        try {
            ResponseEntity<List> listResponseEntity = restTemplate.getForEntity(
                    REST_SERVICE_URI + "/xml/temperature/location/KoreaTech", List.class
            );
            List<Temperature> temperatureList = listResponseEntity.getBody();
            for (int i = 0; i < temperatureList.size(); i++) {
                System.out.println(temperatureList.get(i));
            }
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }

    private static void createTemperature() {
        System.out.println("Testing POST METHOD----------");
        RestTemplate restTemplate = new RestTemplate();

        Temperature temperature = new Temperature();
        temperature.setSensorId("temp3");
        temperature.setTemperature((float)37.0);
        temperature.setDatetime(new java.sql.Date(new Date().getTime()));
        temperature.setLocation("2nd Floor, 4th Engineering Building, KoreaTech");

        try {
            URI uri = restTemplate.postForLocation(
                    REST_SERVICE_URI + "/temperature/",
                    temperature,
                    Temperature.class);
            System.out.println("Location : " + uri.toString());
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }

    private static void updateTemperature() {
        System.out.println("Testing PUT METHOD----------");
        RestTemplate restTemplate = new RestTemplate();

        Temperature temperature = new Temperature();
        temperature.setSensorId("temp1");
        temperature.setTemperature((float)31.1);
        temperature.setDatetime(new java.sql.Date(new Date().getTime()));
        temperature.setLocation("1st Floor, 4th Engineering Building, KoreaTech");

        try {
            restTemplate.put(REST_SERVICE_URI + "/temperature/temp1", temperature);
            System.out.println("PUT METHOD - SUCCESS!");
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }

    private static void deleteTemperature() {
        System.out.println("Testing DELETE METHOD----------");
        RestTemplate restTemplate = new RestTemplate();
        try {
            restTemplate.delete(REST_SERVICE_URI + "/temperature/temp2");
            System.out.println("DELETE METHOD - SUCCESS!");
        } catch (HttpClientErrorException e) {
            System.out.println(e.getStatusCode() + ": " + e.getStatusText());
        }
    }
}
