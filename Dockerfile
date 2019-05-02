FROM ubuntu:14.04

RUN apt-get update \
	&& apt-get install --no-install-recommends -y software-properties-common \
	&& add-apt-repository ppa:bitcoin/bitcoin \
	&& apt-get update \
	&& apt-get --no-install-recommends -y install build-essential libtool autotools-dev autoconf pkg-config libssl-dev \
	libevent-dev libdb4.8-dev libdb4.8++-dev libminiupnpc-dev libboost-dev libboost-system-dev libboost-filesystem-dev \
	libboost-program-options-dev libboost-thread-dev git curl \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*
RUN dpkg-reconfigure locales && \
    locale-gen en_US.UTF-8 && \
    /usr/sbin/update-locale LANG=en_US.UTF-8
ENV LC_ALL en_US.UTF-8

WORKDIR /usr/local/src
RUN git clone https://github.com/Block-Logic-Technology-Group/bltg

WORKDIR /usr/local/src/bltg

RUN ./autogen.sh
RUN ./configure
RUN make

RUN adduser --disabled-password --home /bltg --gecos "" bltg
RUN echo "bltg ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

COPY bltg.conf /bltg/.bltg/bltg.conf
RUN chown -R bltg:bltg /bltg/.bltg

RUN cp /usr/local/src/bltg/src/bltgd /bltgd

USER bltg
WORKDIR /bltg

EXPOSE 17127

CMD ["/bltgd", "-printtoconsole"]
