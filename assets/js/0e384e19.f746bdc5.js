"use strict";(self.webpackChunkdocs=self.webpackChunkdocs||[]).push([[976],{67879:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>d,contentTitle:()=>a,default:()=>h,frontMatter:()=>r,metadata:()=>s,toc:()=>c});const s=JSON.parse('{"id":"intro","title":"PandaLED Docs","description":"PandaLED Docs","source":"@site/docs/intro.md","sourceDirName":".","slug":"/","permalink":"/PandaLED/","draft":false,"unlisted":false,"tags":[],"version":"current","lastUpdatedAt":1737512312000,"sidebarPosition":1,"frontMatter":{"title":"PandaLED Docs","slug":"/","sidebar_position":1},"sidebar":"docs","next":{"title":"Getting Started","permalink":"/PandaLED/category/getting-started"}}');var i=n(74848),o=n(28453);const r={title:"PandaLED Docs",slug:"/",sidebar_position:1},a="Introduction",d={},c=[{value:"What is PandaLED?",id:"what-is-pandaled",level:2},{value:"What makes this project special?",id:"what-makes-this-project-special",level:2},{value:"Where can I get this board?",id:"where-can-i-get-this-board",level:2},{value:"How can I support this project?",id:"how-can-i-support-this-project",level:2}];function l(e){const t={a:"a",h1:"h1",h2:"h2",header:"header",hr:"hr",img:"img",li:"li",p:"p",strong:"strong",ul:"ul",...(0,o.R)(),...e.components},{Button:s}=t;return s||function(e,t){throw new Error("Expected "+(t?"component":"object")+" `"+e+"` to be defined: you likely forgot to import, pass, or provide it.")}("Button",!0),(0,i.jsxs)(i.Fragment,{children:[(0,i.jsx)("h1",{align:"center",children:"PandaLED Docs"}),"\n",(0,i.jsx)("div",{align:"center",children:(0,i.jsx)("img",{width:"200",src:n(4693).A})}),"\n",(0,i.jsxs)("div",{align:"center",children:[(0,i.jsx)(t.p,{children:"ESP32 based controller for Bambu Lab Printer (P1/X1) to control LEDs or other devices."}),(0,i.jsx)(t.p,{children:(0,i.jsx)(t.img,{src:"https://img.shields.io/github/v/release/derDeno/BLWLED?style=for-the-badge&label=PandaLED&color=blueviolet",alt:"GitHub Release"})}),(0,i.jsx)("br",{}),(0,i.jsxs)(t.p,{children:[(0,i.jsx)(t.a,{href:"https://github.com/derDeno/PandaLED/blob/HEAD/LICENSE",children:(0,i.jsx)(t.img,{src:"https://img.shields.io/badge/license-CC--BY--NC--SA--4.0-blue",alt:"license"})}),"\r\n",(0,i.jsx)(t.img,{src:"https://img.shields.io/github/issues/derDeno/PandaLED",alt:"GitHub Issues or Pull Requests"}),"\r\n",(0,i.jsx)(t.a,{href:"https://github.com/prettier/prettier",children:(0,i.jsx)(t.img,{src:"https://img.shields.io/badge/code_style-prettier-ff69b4.svg",alt:"prettier"})}),"\r\n",(0,i.jsx)(t.a,{href:"https://github.com/derDeno/PandaLED/blob/HEAD/CONTRIBUTING.md#pull-requests",children:(0,i.jsx)(t.img,{src:"https://img.shields.io/badge/PRs-welcome-brightgreen.svg",alt:"PRs Welcome"})})]}),(0,i.jsx)("br",{})]}),"\n",(0,i.jsx)(t.header,{children:(0,i.jsx)(t.h1,{id:"introduction",children:"Introduction"})}),"\n",(0,i.jsx)(t.p,{children:"If you want to go straight to the web installer, just press the button below.\r\nOtherwise, follow the getting started guide found in the sidebar."}),"\n",(0,i.jsx)("br",{}),"\n",(0,i.jsx)(s,{label:"Web Installer",size:"lg",link:"https://derdeno.github.io/PandaLED/web-installer.html"}),"\n",(0,i.jsx)("br",{}),"\n",(0,i.jsx)("br",{}),"\n",(0,i.jsx)(t.hr,{}),"\n",(0,i.jsx)(t.p,{children:(0,i.jsx)(t.img,{src:n(58656).A+"",width:"1350",height:"700"})}),"\n",(0,i.jsx)(t.h2,{id:"what-is-pandaled",children:"What is PandaLED?"}),"\n",(0,i.jsx)(t.p,{children:"PandaLED is a control board designed for P1 and X1 Bambu Lab printers. It allows you to connect WLED, classic (analog) LED strips, or any device operating on 12V or 24V with a maximum current of 3A."}),"\n",(0,i.jsx)(t.p,{children:"The board controls connected devices based on events. A complete list of available events is provided on the Mappings page. Using the WebUI, you can define mappings, which provide a simple yet powerful way to associate events with outputs."}),"\n",(0,i.jsxs)(t.p,{children:[(0,i.jsx)(t.strong,{children:"Example:"}),'\r\nYou can map a "finished print" event to the WLED output to turn the LEDs green and have them turn off automatically after 10 minutes.']}),"\n",(0,i.jsx)(t.h2,{id:"what-makes-this-project-special",children:"What makes this project special?"}),"\n",(0,i.jsx)(t.p,{children:"The standout feature of PandaLED is its mapping tool, which provides an intuitive way to connect events with devices. This eliminates the need for firmware modifications or coding skills."}),"\n",(0,i.jsx)(t.p,{children:"Additionally, the exposed GPIO pins enable further customization, allowing you to connect additional devices or design custom expansion boards to enhance functionality."}),"\n",(0,i.jsx)(t.h2,{id:"where-can-i-get-this-board",children:"Where can I get this board?"}),"\n",(0,i.jsx)(t.p,{children:"Currently, the board is in its final development phase and is not yet available for purchase. However, a preorder option is planned for the near future."}),"\n",(0,i.jsxs)(t.p,{children:["To stay updated, consider joining our ",(0,i.jsx)(t.a,{href:"https://discord.gg/8VhnsCXKun",children:"Discord community"}),"."]}),"\n",(0,i.jsx)(t.p,{children:"The entire project is open-source, giving you the freedom to modify it as you like."}),"\n",(0,i.jsx)(t.h2,{id:"how-can-i-support-this-project",children:"How can I support this project?"}),"\n",(0,i.jsx)(t.p,{children:(0,i.jsx)(t.img,{src:n(25659).A+"",width:"300",height:"86"})}),"\n",(0,i.jsx)(t.p,{children:"This project is currently sponsored by JLCPCB but welcomes additional support from the community."}),"\n",(0,i.jsx)(t.p,{children:"If you're interested in supporting this project, you can:"}),"\n",(0,i.jsxs)(t.ul,{children:["\n",(0,i.jsxs)(t.li,{children:["Reach out on Discord ",(0,i.jsx)(t.a,{href:"https://discord.gg/8VhnsCXKun",children:"here"}),"."]}),"\n",(0,i.jsxs)(t.li,{children:["Contribute to the codebase on ",(0,i.jsx)(t.a,{href:"https://github.com/derDeno/PandaLED/blob/HEAD/CONTRIBUTING.md#pull-requests",children:"GitHub"}),"."]}),"\n"]}),"\n",(0,i.jsx)(t.p,{children:"Your contributions and support are greatly appreciated!"})]})}function h(e={}){const{wrapper:t}={...(0,o.R)(),...e.components};return t?(0,i.jsx)(t,{...e,children:(0,i.jsx)(l,{...e})}):l(e)}},4693:(e,t,n)=>{n.d(t,{A:()=>s});const s=n.p+"assets/images/logo-ef7dee5192e27be1a582570100264db2.png"},25659:(e,t,n)=>{n.d(t,{A:()=>s});const s=n.p+"assets/images/jlcpcb-889f0bca2654b6b4ac336c8d4a51f32d.png"},58656:(e,t,n)=>{n.d(t,{A:()=>s});const s=n.p+"assets/images/pcb-3caa75da9b62579f1e68cde3b05d99dd.png"},28453:(e,t,n)=>{n.d(t,{R:()=>r,x:()=>a});var s=n(96540);const i={},o=s.createContext(i);function r(e){const t=s.useContext(o);return s.useMemo((function(){return"function"==typeof e?e(t):{...t,...e}}),[t,e])}function a(e){let t;return t=e.disableParentContext?"function"==typeof e.components?e.components(i):e.components||i:r(e.components),s.createElement(o.Provider,{value:t},e.children)}}}]);