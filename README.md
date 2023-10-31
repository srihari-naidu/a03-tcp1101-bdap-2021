# CONTENTS OF THIS FILE
 * Before you start
 * Compile & Run
 * How to view Logs
<br /><br /><br />



# BEFORE YOU START
### **Clear Screen Function**

This program uses the system command, 'clear' to clear the screen.
If you're using a Windows system, or a terminal which doesn't recognise the 'clear' command, do the following.

    1. Go into src/partials/utils/ and open header.cpp

    2. Modify the clearScreen() function to do system("cls") or any other suitable commands.
<br />

### **Opening Files**

This program uses WSL commands by default to open the Text and HTML report files.
If any of these commands are not recognised, please do the following.
<br /><br />

### Text files

    1. Go into src/partials/ and open ReportTXT.cpp.

    2. Modify the viewReportTXT() function at line 652 of ReportTXT.cpp to launch the report text file however you want.

    3. Disable (comment) the commands out if you'd like to open the text reports manually.

### HTML files

    1. Go into src/partials/ and open ReportTXT.cpp.

    2. Modify the viewReportHTML() function at line 602 of ReportHTML.cpp to launch the report text file however you want.

    3. We've provided an option to launch the HTML report using Brave. You'd just have to comment out the WSL command (line 611) and uncomment the Brave command (line 614).

    4. Disable (comment) the commands out if you'd like to open the text reports manually.
<br />

### **Adding Datafile**

If you're a Buyer and you want to use your own datafile with a different name, instead of replacing the data inside .dat/data.dat, do the following.
<br /><br />

    1. Go into src/datafiles/ and add/place your data file there.

    2. Run the B.D.A.P program.

    3. Log in to your Buyer account and Save your Datafile with a different name.
       Refer to B.D.A.P User Documentation (Save Data File) for steps on how to do that.

<br /><br />



# COMPILE & RUN
### **Option 1:** Run the pre-compiled program.
    cd src/ && && ./BDAP

### **Option 2:** Compile and run the program
    cd src/ && g++ BDAP.cpp -o BDAP && ./BDAP
<br /><br />



# LOGS
### **How to view logs**

    1. Go into src/.dat/ and open logs.dat
<br /><br />


Sidenote:

> Squiggle errors will appear in most parts of the code in VS Code due to file import issues. Compiling and Running BDAP.cpp fixes this.

> For detailed instructions on how to use the program, please refer to the BDAP User Documentation.
