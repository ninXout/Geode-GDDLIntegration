#ifndef RATINGSMANAGER_H
#define RATINGSMANAGER_H

#include <map>

#include <json.hpp>

#include "GDDLRating.h"

using namespace geode::prelude;

enum TierSearchType {
    ANY,
    UNCOMPLETED,
    COMPLETED
};

class RatingsManager {
    static std::map<int, GDDLRating> demonMap;
    static std::map<int, int> ratingsCache;
    inline static std::string cachedListPath = Mod::get()->getSaveDir().string() + "/gddlcache.json";
    inline static int searchedTier = -1;
    inline static TierSearchType tierSearchType{};
    inline static bool searchingForTier = false;

    static GDDLRating parseJson(std::string response);

    static void populateFromSave();

    static void cacheList();

public:
    static int getDemonTier(int id);
    static std::optional<GDDLRating> getRating(int id);

    static std::string getRequestUrl(int id);

    static bool addRatingFromResponse(int id, std::string response);

    static void cacheRatings(const std::string &response);

    static std::map<int, int> getTierStats();

    static bool alreadyCached();

    static GJSearchObject* searchForTier(int tier, bool completed, int page);

    static void setupSearch(int tier, TierSearchType searchType);

    static bool isSearchingForTier();

    static GJSearchObject* getSearchPage(int page);
};


#endif // RATINGSMANAGER_H
