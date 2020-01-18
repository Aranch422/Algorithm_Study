  int nextR=findnext(r,c).first;
            int nextC=findnext(r,c).second;

            if(dfs(nextR,nextC)==0) return 0;
        }
    }