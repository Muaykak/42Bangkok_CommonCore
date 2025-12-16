_This project has been created as part of the 42 
Cirriculum by srussame_

# NetPractice 

## Description

#### Goal

this project's goal is to give student a basic understandings of **Networking**. How one device is able to communicate with another one. How can computer accross the continent be able to connect to our computer.

#### Overview

For this project, you need to solve its networking problems in the folder given the the project's folder. You need to solve all 10 networking problems as a requirement for this project.

To being able to solve all the networking problems, There are knowledges that you need to understand. Such as **TCP/IP addressing, subnet mask, default gateway, routers and switches, OSI layers, etc.**


## Instruction

### Given files
**NetPractice** project gives you 2 files.
#### 1 . en.subject.pdf
- contain descriptions about the project. Requirements and basic instructions on how to open project's file and explanation on each element of the page.
#### 2. net_practice.\*.\*.tgz ( currently net_practice.1.8.tgz)
- **interface** that you need to solve all 10 networking problems.

### How to run the training interface
before we go and solve all 10 networking problems.

1 . after we got the project's files. We need to extract that "net_practice.\*.\*.tgz". Extract to any folder you want. (you can right click on the file then 'Extract' depending on your operating system. Or using command `tar -xf <file_name>` on linux to extract that file)

2 . Inside the extracted folder, run the <u>index.html</u> (You can *right click* and *Open With* and choose whatever web brower you want to open this *html* file. Preferably **Google Chrome** works best for me). and There you go

### Training interface explanation

1 . the index.html page is the first to be encountered. This training interface has 2 modes for you to solve networking problems.
- **Training mode**: The main mode that you are going to practice with. Specify you 42 intra login and click start will let you straight in to the training.
- **Evaluation mode**: This mode is required in evaluation session. This mode will random 3 levels from 6 to 10. and you need to solve it in a specific time limit(currently 15 minutes).

2 . For each level, you will see a non-function **network diagram** (images like computers, switches, routers, internet, and lines that connect these images together)

At the top of the of the page of each level, you will see one or more goals for each level that you need to achieve. You need to specify configurations for each device on the network so that all devices on the network are able to connect properly. There are two buttons at the top of the page that you can use;
- **Check again** to verify that you configuration is able to achieve all the goals.
- **Get my config** to download you configuration file. You will need this to turn in this project.

When you complete all the goals of each level, a new button **"Next level"** will appear that will lead you to the next level. 

(After you go next level, don't forget to export configuration file for each level, you will need 10 of them.)

3 . At the bottom of the page. you will see logs. It is useful to see how each packet is being send and why if you configuration is wrong.

4 . You need to modify all the unshaded fields to make it correct.

## Submission details
You need to pass all 10 levels in training mode and get the configuration file of each level.

Also a Readme.md file that has information about this project.

Overall you would have
- 10 configuration files (1 for each level, and don't forget that you need to enter training mode with you **intra** login)
- 1 Readme.md file

submit all the files in the <u>root</u> your 42 git repository of this project. 

**<u>It is very important that you enter your login in the interface.</u>**

## Resources

### Studied Concepts
For this project, I studied these concepts: **TCP/IP addressing, subnet mask, default gateway, routers and switches, and OSI layers**.

### References
\> [What is TCP/IP?](https://www.ibm.com/docs/en/aix/7.2.0?topic=management-transmission-control-protocolinternet-protocol)

\> [TCP/IP addressing](https://www.ibm.com/docs/en/aix/7.2.0?topic=protocol-tcpip-addressing)

\> [OSI layers](https://www.ibm.com/docs/en/aix/7.2.0?topic=management-network-communication-concepts)


### General Understanding

If you are same as me, who doesn't have any background around IT at all and just born in this era where everything just connects itself to network. It just intuitively. We know what ip address is. But we don't understand how it works. Or *why* it has to be this way. I'll try to explain to the point that you understand the whole idea of this project. without having any prior knowledge at all (or not much lol).

First think of it as if you want to send a book to your friend. But you cannot afford to go to their house because it's too far. One of solutions is to let postman handle that package to you friend.

The next problem is that you can't just tell postman to "send this my friend". He wouldn''t know where your friend is. Instead, you tell postman your friend's <u>location details</u> so that postman can deliver.

This details generally has some kind of <u>format</u> that maybe different for each part of the world. But mainly you specify from big to small like "Thailand Bangkok Bangkae 45/23 34532" or small to big idk.

In the realm of networking, it's the same. Those network cables are similar to roads and streets that connect between houses, towns, cities, states, and countries. and a way to send information on network is using format named **TCP/IP**.

### [What is TCP/IP?]()


### How AI was used in this project
I did use Gemini <u>to clarify my understandings</u>. For example, after i learn new topics like default gateway. I'll try to explain what is default gateway in my own words. And i ask gemini back if my definition on default gateway is correct. If not i would ask gemini to give sites or sources about that topic. I think Gemini is good for scraping informations from internet.
