FROM ubuntu:14.04

RUN apt-get update \
	&& apt-get install --no-install-recommends -y software-properties-common \
	&& add-apt-repository ppa:bitcoin/bitcoin \
	&& apt-get update \
	&& apt-get --no-install-recommends -y install automake autoconf libtool build-essential autotools-dev pkg-config libssl-dev \
	libevent-dev libdb4.8-dev libdb4.8++-dev libminiupnpc-dev libboost-dev libboost-system-dev libboost-filesystem-dev \
	libboost-program-options-dev libboost-thread-dev git curl \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /usr/local/src
RUN git clone https://github.com/Block-Logic-Technology-Group/bltg

WORKDIR /usr/local/src/bltg

RUN ./autogen.sh
RUN ./configure --disable-tests
RUN make

RUN adduser --disabled-password --home /bltg --gecos "" bltg
RUN echo "bltg ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

RUN chown -R bltg:bltg /bltg/.bltg

RUN cp /usr/local/src/bltg/src/bltgd /bltgd
RUN cp /usr/local/src/bltg/src/bltg-cli /bltg-cli

USER bltg
WORKDIR /bltg

EXPOSE 17127

CMD ["/bltgd", "-printtoconsole"]
