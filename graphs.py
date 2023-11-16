import matplotlib.pyplot as plt
import numpy as np
import sys
import csv
import math


#get the command line variables
filename = sys.argv[1]

#declaring variables for tracking total asset type values
financialVal = 0
manufacturedVal = 0
intellectualVal = 0
humanVal = 0
socialVal = 0
naturalVal = 0

#defining switch function
def switch(asset_type):
    #global declare
    global financialVal, manufacturedVal, intellectualVal, humanVal, socialVal, naturalVal
    if asset_type == "financial":
        financialVal += addedValue
        #print("testing-addedFin")
    elif asset_type == "manufactured":
        manufacturedVal += addedValue
        #print("testing-addedMan")
    elif asset_type == "intellectual":
        intellectualVal += addedValue
        #print("testing-addedInt")
    elif asset_type == "human":
        humanVal += addedValue
        #print("testing-addedHum")
    elif asset_type == "social":
        socialVal += addedValue
        #print("testing-addedSoc")
    elif asset_type == "natural":
        naturalVal += addedValue
        #print("testing-addedNat")

def saveGraph():
    
    #parse to x
    x = filename.find('/')  
    #split at x
    directoryKey = filename[:x]  

    #setting permissions for graph save
    graphSavePath = 'piGraphs/' + directoryKey
    
    plt.savefig(graphSavePath)
    plt.close()



with open(filename, 'r') as file:

    assetCsv = csv.DictReader(file)
    #loop through file for values
    #TODO loop through the lines in csv file and add parse for value, count 
    for row in assetCsv:
        asset_type = row['type']

        # get and clean the added value
        value_str = row.get('value', '').strip()
        if value_str and value_str != 'NaN':
            addedValue = float(value_str)
            #print("testing")
        else:
            addedValue = 0  # set to 0 for missing or invalid values

        switch(asset_type)

pieGraph = [financialVal, manufacturedVal, intellectualVal, humanVal, socialVal, naturalVal]
myLabels = ["Financial", "Manufactured", "Intellectual", "Human", "Social", "Natural"]

#eliminate 0 values for sake of graph display
filteredPieGraph = []
filteredLabels = []

#loop and filter 
for value, label in zip(pieGraph, myLabels):
    if value > 0:
        filteredPieGraph.append(value)
        filteredLabels.append(label)


plt.pie(filteredPieGraph, labels = filteredLabels)
plt.show()
saveGraph()



file.close()
