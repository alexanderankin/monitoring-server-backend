# Monitoring Server

This repository addresses a very specific use case pitched to me last summer -
Frequently routers have simple web interfaces to monitor and control their
functionality, but this information is not presented in real time or in a
particularly visually pleasing manner. This is easily fixed by using a
standardized framework like [Node.js](https://nodejs.org/en/) in combination
with a CSS framework like Twitter Bootstrap or something on the front-end.
Options are forgiving for the browser side, but what if the processor in the
server end of the connection doesn't have cross compilation support options
mature enough for runtimes as resource heavy as Node?

Thus the purpose of this project is to bring some minimum viable version of
that feature set to a lightweight, pure-C project.

Perhaps, if things go well enough, it may even be stable enough to go into some
sort of production. Time will tell.
