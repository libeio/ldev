
ARP 只适用于 IPv4，不能用于IPv6。IPv6 中可以用 ICMPv6 替代 ARP 发送邻居探索消息。


## 地址解析

IP 地址属于网络层的地址，它实现了对底层网络物理地址的统一(或者说，屏蔽了底层网络地址的差异)。

为了通过物理网络把互联网分组从一台计算机发送到另一台计算机，网络软件必须把 IP 地址映射成一个物理硬件地址，并用这个硬件地址传输帧。

在从源站到目的站的路径上，每一步都要进行地址映射。这包括:
* 第一，在交付分组的最后一步，分组必须通过一个物理网络送达它的最终目的站。发送分组的计算机在可能实现传输前，必须把最终目的站的因特网地址映射为目的站的物理地址。
* 第二，沿着从源站到目的站的路径，除了最后一步，在任意一点都必须把分组发送到一个中间路由器，因此，发送方必须把中间路由器的因特网地址映射为一个物理地址。


### 动态绑定地址解析

当主机 A 要解析 IP 地址 Ib 时，它广播一个特殊的分组，请求 IP 地址是 Ib 的主机用其物理地址 Pb 作出响应。包括 B 在内的所有主机都接收到这个请求，但只有主机 B 识别出它的 IP 地址，然后发出一个含有自己的物理地址的回答。当 A 收到回答后，就使用该物理地址把互联网分组直接发送给 B 。

上述过程可概括为: 通过地址解析协议，主机只要知道同一物理网络上某个目的主机的 IP 地址，就可以找到该目的站的物理地址。
  

### ARP 报文格式

```shell
    +---------------------------------+---------------------------------+
    |     硬件类型(Ethernet 0x1)       |     上层协议类型(IP:0x0800)      |        
    +----------------+----------------+---------------------------------+
    |  硬件地址长度   |  协议地址长度   |   操作（请求: 0x1; 应答: 0x2）    |
    +----------------+----------------+---------------------------------+
    |                   源 MAC 地址（0~3字节）                           |
    +---------------------------------+---------------------------------+
    |     源 MAC 地址（4~5字节）       |      源 IP 地址（0~1字节）        |
    +---------------------------------+---------------------------------+
    |     源 IP 地址（2~3字节）        |     目的 MAC 地址（0~1字节）      |
    +---------------------------------+---------------------------------+
    |                           目的 MAC 地址                            |
    +-------------------------------------------------------------------+
    |                           目的 IP 地址                             |
    +-------------------------------------------------------------------+
```
字段说明
* 硬件类型字段: 占用 16 比特。用于指定该请求用来获得回应的硬件接口，例如，1 表示以太网。
* 上层协议类型: 占用 16 比特。用于指定将发送方协议地址映射为硬件地址的网络层协议，例如 IP = 0x800。
* 硬件地址长度字段和协议地址长度: 分别占用 8 个比特，分别用于指定硬件地址和协议地址的长度。例如，MAC 地址长度为 6, IP 地址长度为 4。
* 操作字段: 占用 16 比特。用于指定该数据包是 ARP 请求或响应，还是 RARP 请求或响应。例如，操作字段为 1 表示该数据包是一个 ARP 请求；值为 2 表示 ARP 响应；值为 3 表示 RARP 请求；值为 4 表示 RARP 响应。
* 源 MAC 地址/IP 地址字段: 表示发送端的硬件地址(或 IP 地址)。
* 目的 MAC 地址/IP 地址字段: 表示目的端的硬件地址(RARP 应答)或 IP 地址(ARP 应答)。


### ARP 数据包封装

为了能在物理网络中的计算机之间传送 ARP 数据包， ARP 报文应该封装在以太网帧中传送。
```shell
  +----------------+----------------+----------------+--------------------+-----------------+
  |   目的地址      |     源地址     |   类型或长度    |ARP 数据包(28个字节) | 循环冗余检验(CRC)|
  +----------------+----------------+----------------+--------------------+-----------------+
```
说明:
* 某种意义上说，ARP 协议不是 IP 协议的一部分，所以它不包括 IP 报头，而是直接封装在以太网帧的数据部分。
* ARP 广播只限于一个物理网段，不能穿越路由器。ARP 请求报文必须作为广播帧发送，即目的地址填写的是广播地址(所有位全是 1 的以太网地址 FFFFFFFF 被用做广播地址)。按照约定，网络上的每台计算机都被要求"收听"以此作为目的地址的数据包。然而，只有运行 TCP/IP 协议组的主机对 ARP 请求予以响应。
* 由于路由器会隔离广播帧，所以广播帧只能由除路由器之外的其余第 2 层及更低层设备发送，如网桥、交换机、集线器和中继器等发送。
* 数据帧的以太网类型字段用于识别数据字段中携带的 ARP/RARP 数据包类型，即:
    * ARP 请求/响应: 0x0806
    * RARP 请求/响应: 0x8035


### ARP 缓存与其他改进后实现

高速缓存
* 在使用 ARP 服务的主机上保留一个专用的高速缓存(Cache)，用于存放近期的 IP  地址和 MAC 地址的绑定。在发送 ARP 请求时可以先查看这个高速缓存表，若查到所需的 IP 地址与 MAC 地址映射项就不再广播。
* 当地址绑定信息被放入 ARP 缓存时，协议需要设置一个计时器，典型超时时间是 20 分钟。当计时器超出后必须删除这些信息。删除后有两种可能性:
    * 如果没有更多分组要发送到相应的目的站，则什么事也没有。
    * 如果有一个分组必须发送到该目的地，而在缓存中又找不到绑定，则计算机将按照正常的过程，广播一个 ARP 请求并获得绑定。如果目的站仍可达，绑定将再次被放入 ARP 缓存。如果目的站不可达，发送方就会发现目的机器已下线。
* 超时可能发送在任意时刻，可能出现在一次平稳的分组传输期间，造成抖动(jitter)。避免抖动的关键在于提早重新确认，可以通过在传统定时器之外再设一个重新确认定时器来实现。若重新确认定时器超时，则软件将对表项进行检查。如果一些数据报最近还在使用该表项，软件将发送一个 ARP 请求并继续使用该表项。当目标站收到请求并做出回答以后，这两个定时器都被复位。

其他改进
* 每个 ARP 广播分组中都包含发送方的 IP 到物理地址的绑定，接收方在处理 ARP 分组(对目标地址进行解析)之前，先在自己的缓存中更新发送方 IP 到物理地址的绑定信息。
* 所有主机在收到发送方的 ARP 请求时，都会将发送方的 IP 到物理地址的绑定更新到各自的 ARP 缓存中。
* 物理地址变更的主机在启动时，通过广播一个无回报的 ARP 请求，把新地址绑定通知给其他主机。

改进后实现过程
1. 一旦给予软件某个目的站的 IP 地址，软件将查询本站的 ARP 缓存，看是否知道从该 IP 地址到物理地址的映射。如果知道，则软件提取该物理地址，把数据放到包含该地址的帧中并发送；如果不知道，则软件必须广播一个 ARP 请求并等待回答。
2. 当 ARP 分组抵达时，软件首先提取发送方的 IP 地址和物理地址对，并检查本地的高速缓存，查看是否已有该发送方对应的选项，添加或更新该表项。如果接收方是请求目标时，则 ARP 软件用本机(接收方)物理地址形成回答，并把回答直接发送给请求方。
3. 一旦回答到达并且获得地址绑定，ARP 软件就把分组从队列(存放额外的请求分组)中取出，放到一个帧中，并使用该地址绑定来填写帧中的物理目的地址。


### 逆地址解析协议RARP

系统启动时广播发送一个包含自身标识符(通常是本机 MAC 地址，用于接收请求的计算机可以把正确的 IP 地址发在回答中)的 RARP 请求，然后等待响应。网络上的另一台计算机必须被配置成监听 RARP 请求，并生成含有请求方 IP 地址的 RARP 回答。一旦回答到达，系统继续启动，并在所有通信中使用获得的 IP 地址。

RARP 过去曾是没有固定存储的自引导系统所使用的重要协议，但现在已不再重要。


### 代理 ARP 概念

情景描述
* 网络 M 和网络 S 为两个独立的物理网络，路由器 R 连接这两个网络。m1,m2,m3 ... 和 s1,s2,s3 ... 分别为位于这两个物理网络上的主机群。
* 正常来看，网络 M 和网络 S 拥有两个不同的网络号，路由器 R 的路由表内保存有两个直连到 M 和 S 的网络地址，M 和 S 的主机如果想要通信则必须通过 R 进行转发。
* 现在 M 和 S 仍然是两个独立的网络，只是 M 和 S 共用一个网络号，该怎么实现 m1 与 s1 之间的通信呢？

解决方案: R 运行代理 ARP 软件，它捕获 m1 广播的 ARP 请求，发现要通信的 s1 位于另一个物理网络 S 上，R 就会向 m1 发送自己的物理地址作为 ARP 响应。m1 收到响应后，将地址映射(s1IP : RMAC)存放到自己的ARP表中，然后用这个映射把目的站为 s1 的数据发送给 R。R 接收到数据报时，它搜索一个特殊的路由表，之后转发该数据报到 s1。

再谈代理ARP
* 主机之间通过信任机制直接保存通过 ARP 得到的映射，而不去检查其有效性和一致性。
* 因为不一致，可能发生 ARP 表中出现多个 IP 地址映射到同一个物理地址的情况(如 m1 主机要与 s1,s2通信，则 m1 主机的 ARP 表就会保存有 s1IP:RMAC, s2IP:RMAC 两个映射)，但这并没有违反协议规范。
* 代理 ARP 完全隐藏了物理连接的细节，这相当于把路由器 R 隐藏了起来。
* 代理 ARP 仅适用于使用 ARP 进行地址解析的网络，不能应用于更复杂的网络拓扑（如多路由器互连网络）。