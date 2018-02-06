from tandem_repeat import Tandem_repeat
import random
import copy


class Diploid:
    conversionrate = 1

    def __init__(self, l1, l2, i1=None, s1=0.0):
        paternal = Tandem_repeat(l1, i1, s1)
        maternal = Tandem_repeat(l2)
        self._diploid = [paternal, maternal]

    def get_ids(self):
        ids = [x.get_ids() for x in self._diploid]
        return ids

    def get_fitnesses(self):
        fitnesses = [x.get_fitnesses() for x in self._diploid]
        return fitnesses

    def gene_conversion(self):
        r = random.random()
        next_diploid = copy.deepcopy(self)
        if r < Diploid.conversionrate:
            donor = random.choice(self)
            recip = random.randint(0, 1)
            next_diploid[recip] = donor
        return next_diploid


test = Diploid(3, 2, 2, 0.2)
print(test.get_ids())
print(test.get_fitnesses())
print(type(test))

test2 = test.gene_conversion()
print(test2.get_ids())
print(test2.get_fitnesses())
