- short and quick overview
https://www.youtube.com/watch?v=jZE-YSHK_gw
- longer and deeper example
https://developers.redhat.com/videos/youtube/zuEYtMvHN6g/
- written examples:
http://www.kai-waehner.de/blog/2012/05/04/apache-camel-tutorial-introduction/

# camel is an integration framework that wires together endpoints in routes.  

- over 200 components
- build in data transformation, JSON, XML, CSV, java.
- intuitive routing in java or XML
- native rest support for APIs

---

## inspired by enterprise integration patterns EIP
- EIPS
- routing
- transformation
- mediation
- enrichment
- validation
- logging

---

## simple camel route, from a file to a jms queue called order:
~~~~
  from("file:data/inbox")
    .to("jms:queue:order"); 
~~~~

## and back in XML:
~~~~
  <route>
    <from uri="file:data/inbox"/>
    <to uri="jms:queue:order"/>
  </route>
~~~~


good questions:
what do you do if you want to save states with camel?  how do you handle states?


