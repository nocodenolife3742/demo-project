FROM nocodenolife3742/afixl-env:latest

COPY ./src ./build.sh /src/
COPY ./seed /eval
# RUN apt-get update && apt-get upgrade -y && apt autoremove -y