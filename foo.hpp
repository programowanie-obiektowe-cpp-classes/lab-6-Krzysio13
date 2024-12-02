#pragma once

#include "Human.hpp"
#include <algorithm>
#include <list>
#include <vector>

std::vector<char> foo(std::list<Human>& people) {
    std::vector<char> retval(people.size());

    // Inkrementowanie wieku każdej osoby w liście
    std::for_each(people.begin(), people.end(), [](Human& h) { h.birthday(); });

    // Tworzenie wektora wynikowego w odwrotnej kolejności
    std::transform(people.rbegin(), people.rend(), retval.begin(), [](Human& h) {
        // Jeżeli osoba jest 'monsterem' (nie lubi psa ani kota), to 'n'
        return h.isMonster() ? 'n' : 'y';
    });

    return retval;
}

