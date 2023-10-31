#include "../DataFile.cpp"
#include "../statistics/minimum.cpp"
#include "../statistics/maximum.cpp"
#include "../statistics/median.cpp"
#include "../statistics/mean.cpp"
#include "../statistics/variance.cpp"
#include "../statistics/standardDeviation.cpp"
#include "../statistics/pearsonsCorrelation.cpp"
#include "../statistics/distinctDataMember.cpp"
#include "../statistics/histogram.cpp"



// Mohammed Emad
// *******************************************************************
//  StatisticalAnalysis
//
//  task: Menu for Statistical Analysis 
//
// *******************************************************************

void OPT_StatisticalAnalysis()
{
    cout << "+---------------------------------------------------------------------+" << "\n\n"
         << " [1]  Minimum."                                                          << '\n'
         << " [2]  Maximum."                                                          << '\n'
         << " [3]  Median."                                                           << '\n'
         << " [4]  Mean."                                                             << '\n'
         << " [5]  Variance."                                                         << '\n'
         << " [6]  Standard Deviation."                                               << '\n'
         << " [7]  Pearson's Correlation."                                            << '\n'
         << " [8]  Distinct Data Member."                                             << '\n'
         << " [9]  Histogram."                                                        << "\n\n"

         << " (b)  Back."                                                             << "\n\n"
         << "+---------------------------------------------------------------------+" << "\n\n";

    cout << "Choice [12356789 b]" << '\n'
         << "> ";
}

void StatisticalAnalysis(User &user)
{
    do
    {
        header("STAT. ANALYSIS");
        OPT_StatisticalAnalysis();

        char selection;
        cin >> selection;
        cin.ignore(128, '\n');

        switch (tolower(selection))
        {
            case '1': Minimum(user); break;
            case '2': Maximum(user); break;
            case '3': Median(user); break;
            case '4': Mean(user); break;
            case '5': Variance(user); break;
            case '6': StandardDeviation(user); break;
            case '7': PearsonsCorrelation(user); break;
            case '8': DistinctDataMember(user); break;
            case '9': Histogram(user); break;
            case 'b': return;

            default : ERR_InvalidSelection(); break;
        }

    } while (true);
}