FROM debian:stable
LABEL description="Image for developing minishell project." 
WORKDIR /home/minishell
RUN apt-get update 
RUN apt-get install -y clang 
RUN apt-get install -y make 
COPY ./ /home/minishell
CMD [ "/bin/bash" ]