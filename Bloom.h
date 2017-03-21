//
// Created by Ari Trachtenberg on 3/15/17.
//

#ifndef BLOOM_OBJECT_H
#define BLOOM_OBJECT_H

#include <string>

/**
 * Represents a Bloom object corresponding to a character-based Bloom filter.
 */
class Bloom {
public:
    /**
     * Instantiate an empty Bloom object
     * @param mm The length (in characters) of the filter being represented by this object
     */
    Bloom (int mm) : length(mm) {}

    /**
     * Instantiates a Bloom object from a given #filter string
     * @param filter The object is created to represent this #filter.
     * @requires [filter] must have been produced by the {@link #output()} call of some BloomFilter object.
     */
    Bloom (std::string filter) : length(filter.length()) {}

    /**
     * inserts #item into the Bloom object
     */
    virtual void insert(std::string item)=0;

    /**
     * Checks whether #item is in the Bloom object.
     * @return  true if the item may be in the Bloom object
     *          false if the item is definitely not in the Bloom object
     */
    virtual bool exists(std::string item)=0;

    /**
     * @return A filter string of #length characters representing the Bloom object
     */
    virtual std::string output()=0;

    /**
     * Destructor for the Bloom object
     */
    virtual ~Bloom() {};

protected:
    int length; /** The length of the Bloom filter, in chars. */

private:
    /**
     * No default constructor.
     */
    Bloom() {};
};


#endif //BLOOM_OBJECT_H
