import collections


class Solution:
    def isPathCrossing(self, path: str) -> bool:
        mapper = {"N": 0, "E": 1, "S": 2, "W": 3}
        Point = collections.namedtuple('Point', 'i j')
        didj = [
            Point(i, j) for i, j in list(zip((-1, 0, 1, 0), (0, 1, 0, -1)))
        ]
        visited = set([Point(0, 0)])
        current_point = Point(0, 0)
        for current_order in path:
            new_i = current_point.i + didj[mapper[current_order]].i
            new_j = current_point.j + didj[mapper[current_order]].j
            new_point = Point(new_i, new_j)
            if new_point in visited:
                return True
            visited.add(new_point)
            current_point = new_point
        return False
