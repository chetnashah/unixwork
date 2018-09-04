
```c
struct sockaddr {
  sa_family_t sa_family; // 2 bytes
  char sa_data[14]; // 14 bytes
}
// pointer casting between sockaddr and sockaddr_in is valid
struct sockaddr_in {
  short int sin_family; // 2 bytes
  unsigned short int sin_port; // 2bytes
  struct in_addr sin_addr; //Internet address - 4 bytes
  unsigned char sin_zero[8]; // 8 bytes
}
```

Create socket:
When a socket is created this way, it only has family and type, but no actual
address.
```c
int socket(int family, int type, int protocol);
```

Given hostname and port number, get all the address info structure

```c
int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **result);
```

Struct addrinfo

```c
struct addrinfo {
  int ai_flags; //AI_PASSIVE, AI_CANONNAME
  int ai_family; //AF_INET, AF_INET6, AF_UNSPEC
  int ai_socktype: // SOCK_STREAM, SOCK_DGRAM
  int ai_protocol; // use 0 for "any"
  size_t ai_addrlen; //size of ai_addr in bytes
  struct sockaddr *ai_addr; // usually struct sockaddr_in or _in6
  char *ai_canonname; //full canonical hostname
  struct addrinfo *ai_next // next node in a linked list
```

`bind()` allows you to bind a port to socket fd, usually used for servers.
Also known as giving a name to the socket.
```c
int bind(int sockfd, struct sockaddr *my_addr, int addrlen);
```

`connect` allows us to connect to server sockets using sserver addrinfo
```c
int connect(int sockfd, struct sockaddr *serv_addr, int addrlen);
```

`listen` and `accept` to get incoming and connections and serve them.

```c
int listen(int sockfd, int backlog);
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

A typical calling sequence for a server is 
```c
getaddrinfo(); // addr of itself
socket(); // fd
bind(); // fd <-> addr
listen(); // ready to listen
accept(); // ready to serve
```

`accept` returns a newfd that can be used for `send` and `recv`


