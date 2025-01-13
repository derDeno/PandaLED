"use strict";(self.webpackChunkdocs=self.webpackChunkdocs||[]).push([[354],{7360:(A,e,n)=>{n.r(e),n.d(e,{assets:()=>h,contentTitle:()=>s,default:()=>u,frontMatter:()=>r,metadata:()=>t,toc:()=>d});const t=JSON.parse('{"id":"guides/led-test-page","title":"LED Test Page","description":"The LED test page provides a convenient way to directly control the WLED or analog output by sending colors or turning them off.","source":"@site/docs/guides/led-test-page.md","sourceDirName":"guides","slug":"/guides/led-test-page","permalink":"/PandaLED/guides/led-test-page","draft":false,"unlisted":false,"tags":[],"version":"current","sidebarPosition":3,"frontMatter":{"title":"LED Test Page","sidebar_position":3},"sidebar":"guides","previous":{"title":"Debugging","permalink":"/PandaLED/guides/debugging"}}');var i=n(4848),k=n(8453);const r={title:"LED Test Page",sidebar_position:3},s="LED Test Page",h={},d=[{value:"Features",id:"features",level:2}];function c(A){const e={h1:"h1",h2:"h2",header:"header",img:"img",li:"li",ol:"ol",p:"p",strong:"strong",ul:"ul",...(0,k.R)(),...A.components};return(0,i.jsxs)(i.Fragment,{children:[(0,i.jsx)(e.header,{children:(0,i.jsx)(e.h1,{id:"led-test-page",children:"LED Test Page"})}),"\n",(0,i.jsx)(e.p,{children:"The LED test page provides a convenient way to directly control the WLED or analog output by sending colors or turning them off."}),"\n",(0,i.jsx)(e.h2,{id:"features",children:"Features"}),"\n",(0,i.jsxs)(e.ol,{children:["\n",(0,i.jsxs)(e.li,{children:["\n",(0,i.jsx)(e.p,{children:"Color Input:"}),"\n",(0,i.jsxs)(e.ul,{children:["\n",(0,i.jsx)(e.li,{children:"Enter a RGB hex value manually."}),"\n",(0,i.jsx)(e.li,{children:"Use the integrated color picker to select a color."}),"\n"]}),"\n"]}),"\n",(0,i.jsxs)(e.li,{children:["\n",(0,i.jsx)(e.p,{children:"Actions:"}),"\n",(0,i.jsxs)(e.ul,{children:["\n",(0,i.jsxs)(e.li,{children:[(0,i.jsx)(e.strong,{children:"Test"}),': Press the "Test" button to send the selected color to the output.']}),"\n",(0,i.jsxs)(e.li,{children:[(0,i.jsx)(e.strong,{children:"Turn Off"}),': Press "Turn off" to deactivate the selected output.']}),"\n"]}),"\n"]}),"\n",(0,i.jsxs)(e.li,{children:["\n",(0,i.jsx)(e.p,{children:"Rainbow Mode:"}),"\n",(0,i.jsxs)(e.ul,{children:["\n",(0,i.jsx)(e.li,{children:'Use the "Rainbow" button to activate an animated rainbow effect on the WLED output.'}),"\n"]}),"\n"]}),"\n"]}),"\n",(0,i.jsx)(e.p,{children:"This tool simplifies testing and experimenting with your LED outputs directly from the interface."}),"\n",(0,i.jsx)(e.p,{children:(0,i.jsx)(e.img,{src:n(3423).A+"",width:"722",height:"294"})})]})}function u(A={}){const{wrapper:e}={...(0,k.R)(),...A.components};return e?(0,i.jsx)(e,{...A,children:(0,i.jsx)(c,{...A})}):c(A)}},3423:(A,e,n)=>{n.d(e,{A:()=>t});const t="data:image/png;base64,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"},8453:(A,e,n)=>{n.d(e,{R:()=>r,x:()=>s});var t=n(6540);const i={},k=t.createContext(i);function r(A){const e=t.useContext(k);return t.useMemo((function(){return"function"==typeof A?A(e):{...e,...A}}),[e,A])}function s(A){let e;return e=A.disableParentContext?"function"==typeof A.components?A.components(i):A.components||i:r(A.components),t.createElement(k.Provider,{value:e},A.children)}}}]);