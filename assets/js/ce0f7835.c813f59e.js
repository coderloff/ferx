"use strict";(self.webpackChunkferx=self.webpackChunkferx||[]).push([[312],{7363:(e,n,l)=>{l.r(n),l.d(n,{assets:()=>t,contentTitle:()=>c,default:()=>u,frontMatter:()=>d,metadata:()=>s,toc:()=>o});const s=JSON.parse('{"id":"intro/building-project","title":"Building Project","description":"To clone repo:","source":"@site/docs/intro/building-project.md","sourceDirName":"intro","slug":"/intro/building-project","permalink":"/ferx/docs/intro/building-project","draft":false,"unlisted":false,"tags":[],"version":"current","sidebarPosition":2,"frontMatter":{"sidebar_position":2},"sidebar":"tutorialSidebar","previous":{"title":"Project Structure","permalink":"/ferx/docs/intro/project-structure"},"next":{"title":"Contributing","permalink":"/ferx/docs/intro/contributing"}}');var r=l(4848),i=l(8453);const d={sidebar_position:2},c="Building Project",t={},o=[{value:"Commands",id:"commands",level:2},{value:"Makefile",id:"makefile",level:3},{value:"Shell file",id:"shell-file",level:3},{value:"Dependencies",id:"dependencies",level:2}];function a(e){const n={code:"code",h1:"h1",h2:"h2",h3:"h3",header:"header",li:"li",p:"p",pre:"pre",ul:"ul",...(0,i.R)(),...e.components};return(0,r.jsxs)(r.Fragment,{children:[(0,r.jsx)(n.header,{children:(0,r.jsx)(n.h1,{id:"building-project",children:"Building Project"})}),"\n",(0,r.jsx)(n.p,{children:"To clone repo:"}),"\n",(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-bash",children:"git clone https://github.com/coderloff/ferx\n"})}),"\n",(0,r.jsx)(n.p,{children:"After clonning the repo, update the submodules:"}),"\n",(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-bash",children:"git submodule update --init\n"})}),"\n",(0,r.jsxs)(n.p,{children:["That's it! You can build and run the project by entering ",(0,r.jsx)(n.code,{children:"scripts"})," directory and using ",(0,r.jsx)(n.code,{children:"make"})," command or ",(0,r.jsx)(n.code,{children:"BuildProject.sh"})," file."]}),"\n",(0,r.jsx)(n.h2,{id:"commands",children:"Commands"}),"\n",(0,r.jsx)(n.h3,{id:"makefile",children:"Makefile"}),"\n",(0,r.jsxs)(n.p,{children:["Here is the list of each ",(0,r.jsx)(n.code,{children:"make"})," command:"]}),"\n",(0,r.jsxs)(n.ul,{children:["\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make"})," - builds the project and runs it (default: debug)",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make build-debug"})," - builds the project as debug",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make build-release"})," - builds the project as release",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make run-debug"})," - runs the executable of debug",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make run-release"})," - runs the executable of release",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make clean-debug"})," - cleans the build target of debug",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make clean-release"})," - cleans the build target of release",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make clean-debug-all"})," - deletes debug build directory",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"make clean-release-all"})," - deletes release build directory",(0,r.jsx)("br",{})]}),"\n"]}),"\n",(0,r.jsx)(n.h3,{id:"shell-file",children:"Shell file"}),"\n",(0,r.jsxs)(n.p,{children:["Here is the list of each ",(0,r.jsx)(n.code,{children:"BuildProject.sh"})," command:"]}),"\n",(0,r.jsxs)(n.ul,{children:["\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh all"})," - builds the project and runs it (default: debug)",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh build-debug"})," - builds the project as debug",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh build-release"})," - builds the project as release",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh run-debug"})," - runs the executable of debug",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh run-release"})," - runs the executable of release",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh clean-debug"})," - cleans the build target of debug",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh clean-release"})," - cleans the build target of release",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh clean-debug-all"})," - deletes debug build directory",(0,r.jsx)("br",{})]}),"\n",(0,r.jsxs)(n.li,{children:[(0,r.jsx)(n.code,{children:"./BuildProject.sh clean-release-all"})," - deletes release build directory",(0,r.jsx)("br",{})]}),"\n"]}),"\n",(0,r.jsx)(n.h2,{id:"dependencies",children:"Dependencies"}),"\n",(0,r.jsxs)(n.p,{children:["Required dependencies: ",(0,r.jsx)(n.code,{children:"git"}),", ",(0,r.jsx)(n.code,{children:"cmake"}),", ",(0,r.jsx)(n.code,{children:"make"}),", ",(0,r.jsx)(n.code,{children:"ninja"})]})]})}function u(e={}){const{wrapper:n}={...(0,i.R)(),...e.components};return n?(0,r.jsx)(n,{...e,children:(0,r.jsx)(a,{...e})}):a(e)}},8453:(e,n,l)=>{l.d(n,{R:()=>d,x:()=>c});var s=l(6540);const r={},i=s.createContext(r);function d(e){const n=s.useContext(i);return s.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function c(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(r):e.components||r:d(e.components),s.createElement(i.Provider,{value:n},e.children)}}}]);