

### 子网划分

现在，一个 IP 地址的网络标识和主机标识已不再受限于那些传统划分出的地址的类别，而是由一个叫做"子网掩码"的识别码通过子网网络地址细分出比A类、B类、C类更小粒度的网络。这种方式实际上就是将原来A类，B类C类等分类中的主机地址部分用作子网地址，从而将原网络划分为更多个物理网络的一种机制。

子网划分的一般方法是，通过对原始网络地址中主机地址部分的借位来生成子网地址部分，即将 IP 地址的主机号再次划分为子网地址与主机地址两个部分，一部分用来标识子网，另一部分仍然作为主机号。这种子网编址方案，实际上是选择如何把 IP 地址的主机号划分成子物理网络和新的主机号。

子网划分一般通过子网掩码来实现:
* 为要划分成的每个 IP 地址类分配一个默认的子网网络掩码。
* 通过对二进制的网络地址和其网络掩码进行"逻辑与"运算，网络设备可以区分网络地址的网络部分和主机部分。
* 具体实现是: 如果网络上的机器把IP地址中的一些比特看成是网络前缀的部分，则子网掩码中那些对应的比特就被置为"1"；而如果把一些比特看成是主机标识符的部分，则把它们置为"0"。


### 子网数和主机数

每个子网的最大主机数依赖于建立的子网数。

可用的子网数要比允许的最大子网数少 2。其原因在于，有类别间域路由选择协议无法区分全 0 子网(子网部分全为0)和默认网络地址。有类别域间路由器也无法区分全 1 子网的地址和默认的广播地址。因此，当借位数为 1 时，没有可用的子网(2 - 2 = 0)。

在向主机部分借位时，必须至少保留 2 个主机位，以便减去网络地址和广播地址后，仍有最少两个可用主机。因此不能借 7 位。


### 无类别域间路由(CIDR)

路由器路由表条目最大理论数量是 60000 条。但对于大多数机构或团体来说，默认 B 类地址所提供的地址范围通常会超出其需要，而 C 类地址所提供的地址数量又太少，无法满足其需要。如果选择 B 类地址，会造成很多地址闲置不用，CIDR 可用于解决上面的这个问题。

CIDR 的主要作用
* CIDR 支持地址的汇总或汇聚。在地址汇聚方法中，网络供应商在被分配了**地址连续**的 C 类地址块后，又将这些地址块再次分配给他们的用户。此时网络供应商只需要通告通往汇聚块网络地址的路由，而非独立的用户地址。至于内部地址如何划分，则由用户决定。
* 机构或团体可以使用连续的 C 类地址来代替单一的 B 类地址，从而有效地满足其主机地址的需求。CIDR 将这些连续的地址视为一个单一的汇聚起来的超级网络。

CIDR 的工作过程
* CIDR 建立于"超级组网"的基础之上，"超级组网"是"子网划分"的派生词，可看作子网划分的逆过程。
* 子网划分时，从地址的主机部分借位，然后将其合并进网络部分；而在超级组网中，则是将网络部分的某些位合并进主机部分。这种无类别超级组网技术通过将一组较小的无类别网络的路由信息汇聚为一个较大的单一路由表项，减少了因特网路由域中路由表条目(项)的数量。

CIDR 记法: 用一个十进制数表示掩码的长度，并使用一个斜线把它和地址隔开。这样，采用 CIDR 记法的地址块可以这样写: `128.211.168.0/21` 。

    
### 各类网络的子网划分示例

C 类网络划分示例。
以 IP 地址为 194.120.36.35, 向主机部分借 3 位的情形为例。
* 该 IP 地址属于: C 类
* 该类地址最多允许借: 6 位
* 该类地址中有 3 个八位位组用于指定网络部分，1 个八位位组用于指定主机部分
* 该类地址允许的最大主机数是: 256
* 该 IP 地址的子网掩码是: 255.255.255.224
* 子网的 IP 前缀是: /27
* 该子网掩码允许的最大子网数是: 8
* 在该子网掩码网络中，每个子网允许的最大主机数是: 32
* 可用子网数是: 6
* 每个子网的可用主机数是: 30
* 该网络中所有子网可用的主机总数是: 180
* 该 IP 地址所在子网的网络号（网络地址）是: 194.120.36.32
* 该 IP 地址所在子网的广播地址是: 194.120.36.63
* 网络中前两个子网的地址范围:
    ```shell
    194.120.36.0 ~ 194.120.36.31(不可用)
    194.120.36.32 ~ 194.120.36.33
    ```
* 网络中最后两个子网的地址范围:
    ```shell
    194.120.36.192 ~ 194.120.36.223
    194.120.36.224 ~ 194.120.36.225(不可用)
    ```

B 类网络划分示例。
以 IP 地址为 175.25.250.62, 借 6 位的情形为例。
* 该 IP 地址属于: B 类
* 该类地址最多允许借: 14 位
* 该类地址中有 2 个八位位组用于指定网络部分，2 个八位位组用于指定主机部分
* 该类地址允许的最大主机数是: 65536
* 该 IP 地址的子网掩码是: 255.255.252.0
* 子网的 IP 前缀是: /22
* 该子网掩码允许的最大子网数是: 64
* 在该子网掩码网络中，每个子网允许的最大主机数是: 1024
* 可用子网数是: 62
* 每个子网的可用主机数是: 1022
* 该网络中所有子网可用的主机总数是: 63364
* 该 IP 地址所在子网的网络号（网络地址）是: 175.25.248.0
* 该 IP 地址所在子网的广播地址是: 175.25.251.255
* 网络中前两个子网的地址范围:
    ```shell
    172.25.0.0 ~ 172.25.3.255(不可用)
    172.25.4.0 ~ 172.25.7.255
    ```
* 网络中最后两个子网的地址范围:
    ```shell
    172.25.248.0 ~ 172.25.251.255
    172.25.252.0 ~ 172.25.255.255(不可用)
    ```

A 类网络划分示例。
以 IP 地址为 125.225.198.93, 借 21 位的情形为例。
* 该 IP 地址属于: A 类
* 该类地址最多允许借: 22 位
* 该类地址中有 1 个八位位组用于指定网络部分，3 个八位位组用于指定主机部分
* 该类地址允许的最大主机数是: 2^24
* 该 IP 地址的子网掩码是: 255.255.255.248
* 子网的 IP 前缀是: /29
* 该子网掩码允许的最大子网数是: 2097152
* 在该子网掩码网络中，每个子网允许的最大主机数是: 8
* 可用子网数是: 2097150
* 每个子网的可用主机数是: 6
* 该网络中所有子网可用的主机总数是: 12582900
* 该 IP 地址所在子网的网络号（网络地址）是: 125.225.198.88
* 该 IP 地址所在子网的广播地址是: 125.225.198.95
* 网络中前两个子网的地址范围:
    ```shell
    125.0.0.0 ~ 125.0.0.7(不可用)
    125.0.0.8 ~ 125.0.0.15
    ```
* 网络中最后两个子网的地址范围:
    ```shell
    125.255.255.240 ~ 125.255.255.247
    125.255.255.248 ~ 125.255.255.255(不可用)
    ```
