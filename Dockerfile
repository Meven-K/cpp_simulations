# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.202.5/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11/9, Ubuntu 18.04/21.04 on local arm64/Apple Silicon): debian-11, debian-10, debian-9, ubuntu-21.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

ARG PROXY

WORKDIR /usr/src/app

ENV http_proxy ${PROXY}
ENV https_proxy ${PROXY}
ENV ftp_proxy ${PROXY}

RUN apt-get update
RUN apt-get install libglew-dev -y
RUN apt-get install libglfw3 -y
RUN apt-get install libglfw3-dev -y
RUN apt-get install libglm-dev -y
RUN apt-get install g++-multilib -y
RUN apt-get install freeglut3-dev -y
RUN apt-get install libsdl1.2-dev -y