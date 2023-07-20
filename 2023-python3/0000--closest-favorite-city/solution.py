import heapq

class City:
    def __init__(self, name: str, neighbors: list[tuple[str, int]]) -> None:
        self.name = name
        self.neighbors = neighbors

class Destination:
    def __init__(self, city: City, dist: int) -> None:
        self.city = city
        self.dist = dist

    def __lt__(self, other: "Destination") -> bool:
        return self.dist < other.dist

class Area:
    def __init__(self, cities: list[City]) -> None:
        self.cities = cities
        self.h = []

    # Requirement: Given a list of favorite cities, return the city closest to 
    #              the start city.
    # Idea:        Store the favorite cities into a set so checking is in 
    #              constant time. Traverse the map building up a min heap 
    #              indexed by distance from the start city.
    #              If the popped city is part of favorites, return it.
    # Runtime:     O(n log n) - worst case is completely traversing the area 
    #              (O(n)), and inserts to a min heap are O(log n).
    # Space:       O(n) - the heap can grow to the size of the cities
    def closest_favorite(self, start: City, favorites: list[str]) -> str:
        self.h = []
        return self.traverse(set(favorites), start, 0)

    def traverse(self, favorites: set[str], city: City, dist_from_start: int) -> str:
        if city.name in favorites:
            return city.name
        for neighbor in city.neighbors:
            heapq.heappush(self.h, Destination(neighbor[0], dist_from_start + neighbor[1])) # O(logn)
        destination = heapq.heappop(self.h)
        return self.traverse(favorites, destination.city, destination.dist)

"""
A --7--> B --3--> C
 \                ^
  \               |
   \              | 
    2             2
     \            |
      \           |
       v          |
       D -- 5 --> E
"""

cities = []
c = City("C", [])
e = City("E", [(c, 2 )])
b = City("B", [(c, 3 )])
d = City("D", [(e, 5 )])
a = City("A", [(b, 7), (d, 2)])
area = Area(cities)

print("start A, favorites: B, D, closest: " + area.closest_favorite(a, ["B", "D"]))
print("start A, favorites: A, C, E, closest: " + area.closest_favorite(a, ["A", "C", "E"]))
print("start A, favorites: C, E, closest: " + area.closest_favorite(a, ["C", "E"]))
