# Project 5 - Baby Name Voyager
# CS 111, Reckinger
# Aseel Suleiman
# November 5, 2022
# Fall 2022
# This program allows a user to type in a name/multiple names and receive
# a graph of the popularity ranking from data for the last 100 years
# A smaller numbers means it was ranked very high/popular and a larger
# number means the popularity of the name was low.




import matplotlib.pyplot as plt


# This function reads in a file, creates a dictionary with each name and
# corresponding rankings, and loops through the dictionary to find the max
# Parameters: Filenames (rawdata file with stored data of names/ranking)
# Return #1: Mydict (dictionary with each name and the corresponding data)
# Return #2: x (the max number from all the data in the file of rankings)
def readData(filename):
   Mydict = {}
   file = open(filename)
   rawData = file.readlines()
   maxList = []
   for line in rawData:
       Namelist = line.split()
       newList= []
       i = 1
       x = 0


       while i < (len(Namelist)):
           newList.append(int(Namelist[i]))
           i+=1


       name = Namelist[0]
       Mydict[name] = newList
       x = max(newList)


       maxList.append(x)
   x = max(maxList) #used to replace all zeros in the data
   return Mydict, x


# This function creates the dictionary of the lists that will be plotted
# all zeros are repalced with the max number in the data, x. Since a zero
# would appear to look popular on the graphs, when it corresponds to a very low popularity
# Parameter #1: Ranklist (the data with each name and corresponding rankings)
# Parameter #2: x (the max number from the entire data, used to replace zeros)
# Return: Ranklist (the new list with all zeros replaced with x)
def clean_data(Ranklist, x):
   for i in range(len(Ranklist)):
       if Ranklist[i] == 0:
           Ranklist[i] = x
   return Ranklist


# Parameter 1 in this function are Mydict (the dictionary of each name with ranking)
# Parameter 2 is names, which is the input of names entered by the user
# This function is used as the plotting call, plotting each named entered
# The legend is created based on the names entered by the user
def myplt(Mydict, names):
   plt.ion()
   plt.xlabel("years")
   plt.ylabel("ranking")
   plt.title("Most Popular Baby Names, by decade")
   labels1 = [1900,1920,1940,1960,1980,2000]
   ticks = range(0,11,2)
   plt.xticks(ticks, labels1)
   plt.ylim(1020,-10)
   rank = []


   for name in names:
       if name in Mydict.keys():
           rank = Mydict[name]
           cleanList = clean_data(rank,x)
           plt.plot(cleanList, "o--")
           plt.legend(names)
   titlenames = ''.join(names)
   imgtitle = titlenames + ".png"
   plt.savefig(imgtitle)
      
   pass


# This is the main code, it calls all the functions
# This allows the user to enter names while plotting the names and rankings
if __name__ == '__main__':
 Mydict, x = readData("names-data.txt")
 names =[]
 nameString = input("Enter baby names: ")
 names = nameString.split()
 myplt(Mydict, names)
 
