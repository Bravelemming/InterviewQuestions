package jack.kinne;

import org.apache.camel.builder.RouteBuilder;

/**
 * A Camel Java Router
 */
public class MyRouteBuilder extends RouteBuilder {

    @Override
    public void configure() throws Exception {

        from("file:/tmp/input?move=./done")
                .process(new MyLogProcessor() )
                .bean(new MyTransformer(), "TransformContent")
                .to("file:/tmp/output");
    }

}
