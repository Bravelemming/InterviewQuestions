package jack.kinne;

import org.apache.camel.CamelContext;
import org.apache.camel.impl.DefaultCamelContext;

/**
 * A Camel Application, resources here:
 * http://bennet-schulz.com/2017/09/19/getting-started-with-apache-camel-and-java/
 * http://www.kai-waehner.de/blog/2012/05/04/apache-camel-tutorial-introduction/
 * https://www.youtube.com/watch?v=jZE-YSHK_gw
 * Jack Kinne 1.6.19
 */
public class MainApp {


    public static void main(String... args) throws Exception {

        MyRouteBuilder routeBuilder = new MyRouteBuilder();
        CamelContext ctx = new DefaultCamelContext();

        try{
            ctx.addRoutes(routeBuilder);
            ctx.start();
            Thread.sleep(5*60*1000);
            ctx.stop();
        } catch (Exception e){
            e.printStackTrace();
        }

    }

}

