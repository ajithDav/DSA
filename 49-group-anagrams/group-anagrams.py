class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        results=collections.defaultdict(list)
        for val in strs :
            sortValue = ''.join(sorted(val))
            results[sortValue].append(val)
        return list(results.values())