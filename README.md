# Internet-Worm-Propagation-Simulation
You are required to simulate simple worm propagation (like the Code Red worm) in a medium-scale network by using discrete-time simulation technique introduced in class. You can do this programming project on your own computer, with any programming language among C, C++, java, Perl or Python; However, before your submission, make sure your code can run under department Eustis3 machine since the TA will probably needs to test your code on Eustis3 machine for verification.

Worm Propagation Description:

   Assume that in an isolated network with  Ω =100,000 IP address space. The IP addresses can be treated as having value from 1 to 100,000. There are N = 1,000 computers vulnerable to the worm under consideration in this network. These vulnerable computers have the following specific IP addresses:

1, 2, 3,…, 10,

1001, 1002, …., 1010,  

2001, 2002, …, 2010,

…..

 

In other words, each cluster of 10 computers with the consecutive IPs are vulnerable to the worm, and in every 1000 consecutive IP addresses there will be one cluster of 10 vulnerable computers (so there are 100 clusters of vulnerable computers overall). The other 99,000 IPs are not vulnerable to this worm.

   Now assume that the worm starts its infection within this network from 1 initially infected machine, which has the IP address of 1001. At each discrete time tick t, a worm-infected computer can send out scans to η  IP addresses within this network (remember the network has overall Ω IP addresses). If a scan finds a vulnerable computer, it infects the vulnerable computer immediately and this newly infected computer can start infecting others from the next discrete time tick (i.e., no networking delay is considered, or we can say that the delay is assumed to be one time unit). Let us use I(t) to represent the number of infected computers at time tick t (t=1, 2, 3, ….). Thus initially I(0) = 1.

 

1). Simulate a random-scanning worm propagation (like Code Red worm)

Simulate a worm propagation with the scan rate of η= 3 (i.e., an infected computer scans 3 IPs in a time unit).  You need to simulate the worm propagation for 3 independent simulation runs in order to get the vector of the number of infected, I(t), 3 times. Each of your simulation run should end when all vulnerable machines have been infected.

   a). Draw a single figure shows the I(t) from these 3 simulation runs. This figure will exhibit the statistical variance in worm propagation process, but all simulation runs should statistically follow the worm propagation model we introduced in class. (Hint: you can save the simulated I(t) results in a file, then use Excel or Matlab to import the data and draw the figure)

   b). List the time for the worm finishes infecting all vulnerable computers in each run; so you need to provide 3 time values.

 

2). Simulate a local-preference scanning worm propagation  

The above random scanning has been used by most Internet worms, but some other worms have used local-preference scanning (such as Code Red II). You need to simulate such a scanning strategy: for an infected computer with IP value x, for each scan it sends out, it picks the target IP address value y by following the rules below:

   (1). With probability p = 0.8, it picks a random value y such that  y ∈  [x-10, x+10]  (local scan)

   (2). With the remaining probability 0.2, it picks a random value y between 1 to 100,000 (uniform scan)

   Again we assume that the worm starts its infection within this network from 1 initially infected machine, which has the IP address of 1001. You need to simulate the worm propagation with scan rate of η=3 for 3 simulation runs, then

      a). Draw one figure showing the I(t) of these 3 simulation runs.

      b). List the time for the worm finishes infecting all vulnerable computers in each run; so you need to provide 3 time values.
