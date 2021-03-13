# Check http://releases.llvm.org/download.html#10.0.0 for the latest available binaries
FROM debian:stable
LABEL description="Container for developing minishell project." 
WORKDIR /home/minishell
RUN apt-get update 
# RUN apt-get install -y g++ 
RUN apt-get install -y clang 
RUN apt-get install -y make 

COPY ./ /home/minishell

CMD [ "/bin/bash" ]

#docker run --rm -it minishell:dev