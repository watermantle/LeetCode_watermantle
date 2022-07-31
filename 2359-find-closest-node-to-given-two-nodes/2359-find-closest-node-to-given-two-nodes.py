class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        graph = {}
        for i in range(len(edges)):
            graph[i] = edges[i]
        
        def search(graph, s):
            idx = 0
            seen = {s: idx}
            while True:
                v_next = graph.get(s, -1)
                if v_next in seen:
                    break
                if v_next != -1:
                    idx += 1
                    seen[v_next] = idx
                    s = v_next
                else:
                    break
            return seen
        
        path1 = search(graph, node1)
        path2 = search(graph, node2)
        
        print(path1)
        print(path2)
        
        res = -1
        nodes_shared = set(path1.keys()) & set(path2.keys())
        if not nodes_shared: return res
        
        running_min = float('inf')
        for node in nodes_shared:
            dis = max(path1[node], path2[node])
            if running_min > dis:
                running_min = dis
                res = node
            elif running_min == dis:
                res = min(node, res)
        return res