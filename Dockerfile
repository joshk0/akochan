FROM alpine AS builder

RUN apk add --no-cache boost boost-dev build-essential g++ make

COPY . /source
WORKDIR /source

ENV NPROCS 4
RUN make -f Makefile_Linux NPROCS=${NPROCS} -C ai_src
RUN make -f Makefile_Linux NPROCS=${NPROCS}

FROM alpine

RUN apk add --no-cache boost
COPY --from=builder /source/system.exe /usr/local/bin/akochan

USER alpine
CMD [/usr/local/bin/akochan]
