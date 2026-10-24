class Solution:

    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def isLeap(year):
            return year % 4 == 0 and year % 100 != 0 or year % 400 == 0
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if date1 > date2:
            date1, date2 = date2, date1
        y1, m1, d1 = map(int, date1.split("-"))
        y2, m2, d2 = map(int, date2.split("-"))
        result = 0
        for year in range(y1, y2):
            result += 365 + isLeap(year)
        days[1] = 29 if isLeap(y1) else 28
        result -= sum(days[ : m1 - 1]) + d1
        days[1] = 29 if isLeap(y2) else 28
        result += sum(days[ : m2 - 1]) + d2
        return result
        