# M3OEP-taschulz

Tucker Schulz

My program is a website, and all installs should be on the remote site.
https://taschulz.w3.uvm.edu/M3OEP-taschulz

This program consists of a basic html website to take user input via a form. Using a php script I create variables for the input
and write them to a csv file. I then called a c++ program via command line and passed it the csv's file path. My c++ program reads
the csv file and creates a Integrated Reporting Frame object which has a vector full of assets. The c++ program then prints an html table to display the assets. It also calls a python script via command line which creates a pie chart and saves it to the remote site. The pi chart is then displated below the table.

Known bugs: 
On site refresh the form resubmits, this is a bug I'd like to fix for next module.

Future work:
I spent a lot of time on this project just learning, practing, and setting up connections between the different languages and environments I was working in. I am really excited about where I got to, but it is not quite where I had envisioned it. Going forward I'd like to add more functionality and to the c++ program as well as more visuals with matplot and numpy.

I really don't enjoy grading myself, but based on level of effort and pass OEP grades, I feel I've earned (60-70) points.
