FROM alpine:3.11
WORKDIR /rathena
RUN apk add --no-cache git make gcc g++ gdb zlib-dev mariadb-dev ca-certificates linux-headers bash
ENTRYPOINT [ "bash" ]
