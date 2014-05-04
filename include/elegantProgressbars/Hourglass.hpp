#pragma once

#include <string>
#include <sstream>
#include <cassert> /*assert*/
#include <tuple>
#include <vector>

#define HTOP   "          #############      "
#define HE1    "          #           #      "
#define HE2    "           #         #       "
#define HE3    "             #     #         "
#define HE4    "               # #           "
#define H5     "                #            "
#define HE6    "               #.#           "
#define HE7    "             #  .  #         "
#define HE8    "           #    .    #       "
#define HE9    "          #     .     #      "
#define HBOT   "          #############      "

#define HF1    "          #############      "
#define HF2    "           ###########       "
#define HF3    "             #######         "
#define HF4    "               ###           "

#define HF6    "               ###           "
#define HF7    "             #######         "
#define HF8    "           ###########       "
#define HF9    "          #############      "

#define HR1    "          ###       ###      "
#define HR2    "           ###     ###       "
#define HR3    "             ##   ##         "
#define HR4    "               #.#           "

#define HR6    "               #.#           "
#define HR7    "             #  #  #         "
#define HR8    "           #   ###   #       "
#define HR9    "          #   #####   #      "


#define CLR    "                             "

#define HH0    "       ####             #### "
#define HH1    "       ######         ##   # "
#define HH2    "       #########   ###     # "
#define HH3    "       ############        # "
#define HH4    "       #########   ###     # "
#define HH5    "       ######         ##   # "
#define HH6    "       ####             #### "
    

namespace ElegantProgressbars{
    

/** Produces an ascii-art hourglass to visualize time
 *
 * The hourglass will turn after all the sand ran through. The progress is not
 * related to the number of turns or the filling state of the hourglass, since
 * nobody can be sure how much sand there is inside. Hourglasses are not the
 * most accurate way to measure time. Do not be surprised if there is still
 * sand left at the end of the process.
 */
class Hourglass{
    
  public:
  inline static std::tuple<std::string, unsigned> print(
      unsigned part,
      unsigned const maxPart,
      float percentage = -1.f
      ){
    static std::vector<std::string> hg1 =  {CLR, CLR, HTOP, HF1, HF2, HF3, HF4, H5, HE6, HE7, HE8, HE9, HBOT, CLR, CLR};
    static std::vector<std::string> hg2 =  {CLR, CLR, HTOP, HF1, HF2, HF3, HF4, H5, HE6, HE7, HE8, HR9, HBOT, CLR, CLR};
    static std::vector<std::string> hg3 =  {CLR, CLR, HTOP, HE1, HF2, HF3, HF4, H5, HE6, HE7, HE8, HF9, HBOT, CLR, CLR};
    static std::vector<std::string> hg4 =  {CLR, CLR, HTOP, HE1, HF2, HF3, HF4, H5, HE6, HE7, HR8, HF9, HBOT, CLR, CLR};
    static std::vector<std::string> hg5 =  {CLR, CLR, HTOP, HE1, HE2, HF3, HF4, H5, HE6, HE7, HF8, HF9, HBOT, CLR, CLR};
    static std::vector<std::string> hg6 =  {CLR, CLR, HTOP, HE1, HE2, HF3, HF4, H5, HE6, HR7, HF8, HF9, HBOT, CLR, CLR};
    static std::vector<std::string> hg7 =  {CLR, CLR, HTOP, HE1, HE2, HE3, HF4, H5, HE6, HF7, HF8, HF9, HBOT, CLR, CLR};
    static std::vector<std::string> hg8 =  {CLR, CLR, HTOP, HE1, HE2, HE3, HE4, H5, HF6, HF7, HF8, HF9, HBOT, CLR, CLR};
    static std::vector<std::string> hg9 =  {CLR, CLR, CLR,  CLR, HH0, HH1, HH2, HH3,HH4, HH5, HH6, CLR, CLR,  CLR, CLR};
    static std::vector<std::vector<std::string> > hglass = {  hg1, hg2, hg3, hg4, hg5, hg6, hg7, hg8, hg9};

    static unsigned tic = 0;
    std::stringstream stream;

    if(percentage < 0)
        percentage = static_cast<float>(part) / static_cast<float>(maxPart);
    assert(maxPart > 0);
    assert(percentage <= 1.f);

    unsigned framecount = hglass.size();
    auto frame = hglass[(tic/8)%framecount];
    for(unsigned i=0 ; i< frame.size() ; ++i){
      stream << frame[i] << std::endl;
    }
    ++tic;
    return std::tuple<std::string, unsigned>(stream.str(), frame.size());
  }
};

}