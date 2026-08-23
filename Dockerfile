FROM ubuntu AS builder

COPY . .
RUN apt update && apt install cmake ninja-build gcc g++ -y
RUN rm -rf build && mkdir build && mkdir -p dist && cmake -S . -B build -G Ninja && cmake --build build && cp build/fastshell dist/fastshell

FROM debian:stable-slim

COPY --from=builder dist .
CMD [ "./fastshell" ]