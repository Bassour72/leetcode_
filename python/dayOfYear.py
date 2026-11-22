
class Solution:
    def isLeapYear(self, year: int) -> bool:
        return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

    def dayOfYear(self, date: str) -> int:
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        
        yearNumber = int(date[0:4])
        monthNumber = int(date[5:7])
        dayNumber = int(date[8:10])
        
        if self.isLeapYear(yearNumber):
            months[1] = 29
            
        totalDay = 0
        for i in range(monthNumber - 1):
            totalDay += months[i]
            
        totalDay += dayNumber
        return totalDay

if __name__ == '__main__':
    sol = Solution()
    print(sol.dayOfYear("2019-01-09"))  # Output: 9
    print(sol.dayOfYear("2019-02-10"))  # Output: 41
    print(sol.dayOfYear("2004-03-01"))