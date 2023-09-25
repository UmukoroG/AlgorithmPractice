from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        stack=deque()
        closeToOpen_mp={")":"(","]":"[","}":"{"}

        for i in s:
            if i in closeToOpen_mp:
                if stack and stack[-1]==closeToOpen_mp[i]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(i)
        return True if not stack else False