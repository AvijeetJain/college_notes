import com.learnwebservices.services.hello.*;

public class Main {

    public static void main(String[] args) {
        HelloEndpointService service = new HelloEndpointService();
        HelloEndpoint port = service.getHelloEndpointPort();
        HelloRequest request = new HelloRequest();

        request.setName("CCLab");

        HelloResponse response = port.sayHello(request);
        System.out.println(response.getMessage());
    }
}