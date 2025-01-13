// @ts-check
const sidebars = {
  docs: [
    'intro',
    {
      type: 'category',
      label: 'Getting Started',
      link: {
        type: 'generated-index',
      },
      collapsed: false,
      items: [
        'getting-started/installation',
        'getting-started/what-can-i-connect',
        'getting-started/sourcing-parts',
      ],
    },
    {
      type: 'category',
      label: 'API',
      link: {
        type: 'doc',
        id: 'api/introduction',
      },
      items: [
        'api/settings',
        'api/mapping',
        'api/file',
        'api/other',
      ],
    }
  ],
  guides: [
    {
      type: 'category',
      label: 'Mappings',
      link: {
        type: 'doc',
        id: 'guides/mappings/introduction',
      },
      items: [
        'guides/mappings/events',
      ],
    },
    {
      type: 'category',
      label: 'Setup Device',
      link: {
        type: 'generated-index',
        title: 'PandaLED Setup Device',
      },
      items: [
        'guides/setup-device/device',
        'guides/setup-device/printer',
        'guides/setup-device/wifi',
        'guides/setup-device/mappings',            
        'guides/setup-device/update-backup-restore',
      ],
    },
    'guides/debugging',
    'guides/led-test-page',
  ],
};

export default sidebars;
