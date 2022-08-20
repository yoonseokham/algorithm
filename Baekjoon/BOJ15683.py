import collections
import copy
import sys
import itertools


class cctvSolver:
    def __init__(self, cctv_map):
        self._n = len(cctv_map)
        self._m = len(cctv_map[0])
        self._cctv_map = cctv_map
        self.point = collections.namedtuple("Point", 'i j space_kind')
        self._directions = ['up', 'right', 'down', 'left']
        self.answer = self._n * self._m

    def get_direction_mapper(self, cctv):
        index = cctv.i
        jndex = cctv.j
        direction_mapper = collections.defaultdict(list)
        for direction, index_range in zip(
            ["up", "down"],
            [range(index - 1, -1, -1),
             range(index + 1, self._n)]):
            for i in index_range:
                if self._cctv_map[i][jndex] == 6:
                    break
                direction_mapper[direction].append(
                    self.point(i, jndex, self._cctv_map[i][jndex]))
        for direction, jndex_range in zip(
            ["right", "left"],
            [range(jndex + 1, self._m),
             range(jndex - 1, -1, -1)]):
            for j in jndex_range:
                if self._cctv_map[index][j] == 6:
                    break
                direction_mapper[direction].append(
                    self.point(index, j, self._cctv_map[index][j]))
        return direction_mapper

    def get_index_far_direction(self, direction, index):
        current_index = self._directions.index(direction)
        return self._directions[(current_index + index) % 4]

    def get_cctv_watch_box(self, direction, cctv_kind):
        if cctv_kind == 1:
            return [direction]
        if cctv_kind == 2:
            return [direction, self.get_index_far_direction(direction, 2)]
        if cctv_kind == 3:
            return [direction, self.get_index_far_direction(direction, 1)]
        if cctv_kind == 4:
            return [
                direction,
                self.get_index_far_direction(direction, 1),
                self.get_index_far_direction(direction, 2),
            ]
        return [
            direction,
            self.get_index_far_direction(direction, 1),
            self.get_index_far_direction(direction, 2),
            self.get_index_far_direction(direction, 3),
        ]

    def get_cctv_list(self):
        cctv_list = []
        for i in range(self._n):
            for j in range(self._m):
                if self._cctv_map[i][j] in (1, 2, 3, 4, 5):
                    cctv_list.append(self.point(i, j, self._cctv_map[i][j]))
        return cctv_list

    def get_direction_case(self, cctv_kind):
        if cctv_kind == 2:
            return ["up", "left"]
        if cctv_kind == 5:
            return ["up"]
        return self._directions

    def get_every_cases(self):
        cctv_list = self.get_cctv_list()
        each_element_four_direction = [
            list(
                itertools.product(
                    self.get_direction_case(cctv_list[i].space_kind),
                    [cctv_list[i]])) for i in range(len(cctv_list))
        ]
        return list(itertools.product(*each_element_four_direction))

    def count_blind_spot(self, case):
        blind_spot = 0
        temp_watch_map = copy.deepcopy(self._cctv_map)

        for cctv_info in case:
            direction, cctv = cctv_info
            cctv_watch_directions = self.get_cctv_watch_box(
                direction, cctv.space_kind)
            for direction in cctv_watch_directions:
                for point in self.get_direction_mapper(cctv)[direction]:
                    i, j, space_kind = point
                    if not space_kind:
                        temp_watch_map[i][j] = '#'
        for i in range(self._n):
            for j in range(self._m):
                if temp_watch_map[i][j] == 0:
                    blind_spot += 1
        return blind_spot

    def __call__(self):
        every_cases = self.get_every_cases()
        for case in every_cases:
            self.answer = min(self.count_blind_spot(case), self.answer)
        return self.answer


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    cctv_map = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    print(cctvSolver(cctv_map)())
